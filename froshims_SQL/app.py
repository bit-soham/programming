from cs50 import SQL
from flask import Flask, render_template, request, redirect

app = Flask(__name__)

db = SQL("sqlite:///froshims.db")


# global variables are capital in but in other files they become lower case


SPORTS = {
    "Basketball",
    "Soccer",
    "Frisbee"
}

@app.route("/",)
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/deregister", methods = ["POST"])
def deregister():

    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id = ?", id)

    return redirect("/registrants")

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