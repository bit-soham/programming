from  flask import Flask, render_template, request

app = Flask(__name__)
# turn this file with the name name into a flask applicatioon

                        # methods to excpect
@app.route("/", methods =["GET","POST"])# it is the action taken by the form her the app only routes the acton to  their specific ways)# / means default page
def index(): #it is like defining a function name doesn't matter
    if request.method == "GET":
        return render_template("index.html")
    elif request.method == "POST":
            # if "name" in request.args:
            #     name = request.args["name"]
            # else:
            #     name = "world"
            # all the above can be written as
        return render_template("greet.html", name=request.form.get("name", "world"))
# the orange name is like placeholder variable is name therefore the placeholder name is also sent to html


