from flask import Flask
import pymongo

conn = pymongo.MongoClient("mongodb://localhost:27017/?readPreference=primary&appname=MongoDB%20Compass&ssl=false")
coll = conn["testlogin"]
db = coll["testlogin"]


app = Flask(__name__)





if __name__ == "__main__":
    app.run(debug=True)