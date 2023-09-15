import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash
from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

STOCKS = {}



@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    current_user_id = session["user_id"]
    cash_left = round(db.execute("SELECT cash FROM users WHERE id = ?", current_user_id)[0]['cash'], 2) # it is a list of dictionaries
    cash_left = round(cash_left, 2)
    stocks = db.execute("SELECT * FROM stocks WHERE user_id = ?", current_user_id)
    return render_template("portfolio.html", stocks=stocks, cash_left=cash_left)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        # geting this session's user id
        current_user_id = session["user_id"]
        #bringing the stocks table
        stocks = db.execute("SELECT * FROM stocks WHERE user_id = ?", current_user_id)
        #taking the values
        shares = db.execute("SELECT * FROM shares WHERE user_id = ?", current_user_id)
        symbol = request.form.get("buysymbol")
        share = float(request.form.get("shares"))
        # bringing the stocks
        shares = db.execute("SELECT * FROM shares WHERE user_id = ?", current_user_id)
        define = {}
        define = lookup(symbol)
        # check if the company is not there
        if define is None:
            return render_template("apology.html", top="Not a Valid Company name")
        # assigning values
        symbol = define['symbol']
        name = define['name']
        price = float(define['price'])
        total = round(price * share, 2)
        # finding out if money left
        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", total, current_user_id)
        cash_left = db.execute("SELECT cash FROM users WHERE id = ?", current_user_id)[0]['cash'] # it is a list of dictionaries
        cash_left = round(cash_left, 2)
        if cash_left < 0:
            db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", total, current_user_id)
            return apology("SORRY YOU DO NOT HAVE ANY CASH")
        # checking the shares table for already used company then we only update the values
        # a dictionary to store the values of the lookup function
        if any(row['symbol_id'] == symbol for row in shares):
            db.execute("UPDATE shares SET total_shares = total_shares + ? WHERE symbol_id = ? AND user_id = ?", share, symbol, current_user_id)
        else:
            db.execute("INSERT INTO shares (user_id, symbol_id, total_shares) VALUES(?, ?, ?)", current_user_id, symbol, share)
        db.execute("INSERT INTO stocks (user_id, symbol_id, name, shares, price, total) VALUES(?, ?, ?, ?, ?, ?)", current_user_id, symbol, name, share, price, '-$' + str(total))
        db.execute("INSERT INTO histories (user_id, method, symbol_id, name, shares, price, total) VALUES(?, ?, ?, ?, ?, ?, ?)", current_user_id, "BUY", symbol, name, share, price, '-$' + str(total))
        stocks = db.execute("SELECT * FROM stocks WHERE user_id = ?", current_user_id)
        share= int(share)
        return render_template("success.html", heading="Success", top="Dang, you're smart. Not only did you buy " +str(share)+" shares but you bought it from "+ symbol, bottom="You have invested a whooping $" + str(total))

    return render_template("buy.html", symbol=request.args.get("buysymbol"))

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    current_user_id = session["user_id"]
    subtract_id = db.execute("SELECT id FROM histories WHERE user_id = ?", current_user_id)[0]['id']
    histories = db.execute("SELECT * FROM histories WHERE user_id = ?", current_user_id)

    return render_template("history.html", histories=histories, subtract_id=subtract_id)

@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        define = {}
        symbol = request.form.get("quote")
        define = lookup(symbol)
        return render_template("quoted.html", symbol=define)
    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":

        username = request.form.get("username")
        password = request.form.get("password")
        repeatpassword = request.form.get("repeatpassword")

        # Ensure username was submitted
        if not username:
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not password:
            return apology("must provide password", 403)

        if password != repeatpassword :
            return render_template("apology.html", top="password does not match")
        password = generate_password_hash(password)
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, password)

        return render_template("success.html", heading="Successfully registered", top="Thank you for registering", bottom="Hope you enjoy our services")


    return render_template("register.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)
        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():

    """Sell shares of stock"""
    if request.method == "POST":
        current_user_id = session["user_id"]
        symbol = request.form.get("company")
        share = int(request.form.get("shares"))
        result = db.execute("SELECT total_shares FROM shares WHERE symbol_id = ? AND user_id = ?", symbol, current_user_id)
        # return render_template("test.html", cash=share)
        if result:
            available_shares = int(result[0]['total_shares'])
            check = available_shares - share
            if check < 0:
                return apology("You do not have enough shares")
        else:
            return apology("You do not have any shares of the company")
        define = lookup(symbol)
        symbol = define['symbol']
        name = define['name']
        price = define['price']
        share = float(share)
        total = round(price * share, 2)
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?" , total, current_user_id)
        db.execute("UPDATE shares SET total_shares = total_shares - ? WHERE symbol_id = ? AND user_id = ?", share, symbol, current_user_id)
        db.execute("INSERT INTO stocks (user_id, symbol_id, name, shares, price, total) VALUES (?, ?, ?, ?, ?, ?)", current_user_id, symbol, define['name'], share, price, '+$' + str(total))
        db.execute("INSERT INTO histories (user_id, method, symbol_id, name, shares, price, total) VALUES(?, ?, ?, ?, ?, ?, ?)", current_user_id, "SELL", symbol, name, share, price, '+$' + str(total))
        db.execute("DELETE FROM shares WHERE total_shares = 0")
        stocks = db.execute("SELECT * FROM stocks WHERE user_id = ?", current_user_id)
        cash_left = db.execute("SELECT cash FROM users WHERE id = ?", current_user_id)[0]['cash'] # it is a list of dictionaries
        cash_left = round(cash_left, 2)
        share = int(share)
        return render_template("success.html", heading="Sold Successfully", top="Damn you Sold "+str(share)+" of "+symbol+" company at the perfect time" , bottom="You earned a whooping $"+str(total) )

    current_user_id = session["user_id"]
    shares = db.execute("SELECT * FROM shares WHERE user_id = ?", current_user_id)
    return render_template("sell.html", shares=shares)

@app.route("/add", methods=["GET", "POST"])
@login_required
def add():
    if request.method == "POST":
        amount = float(request.form.get("amount"))
        amount = round(amount, 2)
        method = request.form.get("method")
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", amount, session["user_id"])
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session['user_id'])[0]['cash']
        cash = round(cash, 2)
        db.execute("INSERT INTO histories (user_id, symbol_id, name, shares, price, total, method) VALUES(?, ?, ?, ?, ?, ?, ?)", session["user_id"], method, "Money added", '+$' + str(amount), "Current cash:", '$' + str(cash + amount), "ADD")
        histories = db.execute("SELECT * FROM histories WHERE user_id = ?", session["user_id"])
        return render_template("success.html", heading="Success", top="$"+str(amount)+" has been transferred to your balance", bottom="Hope you are enjoying our services")

    cash = db.execute("SELECT cash FROM users WHERE id = ?", session['user_id'])[0]['cash']
    cash = round(cash, 2)
    return render_template("add.html", cash=cash)
@app.route("/success")
@login_required
def success():
    return render_template("portfolio.html")

@app.route("/shares")
@login_required
def shares():
    shares = db.execute("SELECT * FROM shares WHERE user_id = ?" , session['user_id'])
    return render_template("shares.html", shares=shares)
