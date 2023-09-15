from cs50 import  SQL
from flask import Flask, render_template, request, redirect, session
from flask_session import Session

app = Flask(__name__)


app = Flask(__name__)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# global variables are capital in but in other files they become lower case

db = SQL("sqlite:///froshims.db")

SPORTS = {
    "Basketball",
    "Soccer",
    "Frisbee"
}

@app.route("/",)
def index():
    if not session.get("name"):
        return redirect("/login")
    return render_template("index.html", sports=SPORTS)
@app.route("/login", methods = ["GET", "POST"])
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name")
        return redirect("/")
    return render_template("login.html")


@app.route("/logout")
def logout():
    session["name"] = None
    return redirect("/")

@app.route("/deregister", methods = ["POST"])
def deregister():
    id = request.form.get("id")
    name = request.form.get("name")

    if(name == session["name"]):
        if id:
            db.execute("DELETE FROM registrants WHERE id = ?", id)
    return redirect("registrants")


@app.route("/register", methods = ["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name or sport not in SPORTS:
        return render_template("failure.html") # return stops the function register from working anymore
    # to add in dictionary
    # sport = request.form.get("sport")
    # REGISTRANTS[name] = sport

    # to add in SQL
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)

    return redirect("/registrants")

@app.route("/registrants")
def registrants(): # you can't call a function with name of a variable
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)