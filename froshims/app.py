from flask import Flask, render_template, request

app = Flask(__name__)


REGISTRANTS = {}
# global variables are capital in but in other files they become lower case
SPORTS = {
    "Basketball",
    "Soccer",
    "Frisbee"
}

@app.route("/",)
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods = ["POST"])
def register():
    name = request.form.get("name")
    if not name:
        return render_template("failure.html") # return stops the function register from working anymore
    sport = request.form.get("sport")
    if sport not in SPORTS:
        return render_template("failure.html" )
    REGISTRANTS[name] = sport

    return render_template("sucess.html")

@app.route("//registrants")
def registrants(): # you can't call a function with name of a variable
    return render_template("registrants.html", registrants=REGISTRANTS)