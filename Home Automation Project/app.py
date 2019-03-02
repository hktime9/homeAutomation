'''
Adapted excerpt from Getting Started with Raspberry Pi by Matt Richardson
Modified by Rui Santos
Complete project details: http://randomnerdtutorials.com
'''

import RPi.GPIO as GPIO
import time
from flask import Flask, render_template, request
app = Flask(__name__)

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

pidIn= 17
pidIndicator= 18
TvSignal= 2

pins = {
   23 : {'name' : 'Study Table Light', 'state' : GPIO.LOW},
   24 : {'name' : 'Night Light', 'state' : GPIO.LOW}
   }

for pin in pins:
   GPIO.setup(pin, GPIO.OUT)
   GPIO.output(pin, GPIO.LOW)

GPIO.setup(pidIn, GPIO.IN) #PIR in pin
GPIO.setup(pidIndicator, GPIO.OUT, initial= GPIO.LOW) #movement indicator LED
GPIO.setup(TvSignal, GPIO.OUT, initial= GPIO.LOW) #TV signal pin


@app.route("/")
def main():
   print("New Connection by: {}").format(request.remote_addr)
   for pin in pins:
      pins[pin]['state'] = GPIO.input(pin)
   templateData = {
      'pins' : pins
      }
   return render_template('main.html', **templateData)

@app.route("/<changePin>/<action>")
def action(changePin, action):
   changePin = int(changePin)
   deviceName = pins[changePin]['name']
   cmdString= deviceName+" requested "+action+" by: "+request.remote_addr
   print(cmdString)
   if action == "on":
      GPIO.output(changePin, GPIO.HIGH)
      message = "Turned " + deviceName + " on."
   if action == "off":
      GPIO.output(changePin, GPIO.LOW)
      message = "Turned " + deviceName + " off."

   for pin in pins:
      pins[pin]['state'] = GPIO.input(pin)

   templateData = {
      'pins' : pins
   }

   return render_template('main.html', **templateData)
   
@app.route("/movementCheck")
def giveMovementSummary():
   print("Checking Movement for 20 seconds as requested by {}").format(request.remote_addr)
   timeDuration= 20

   tEnd= time.time() + timeDuration
   sumt= 0
   count= 0
   while(True):
      if(count==200):
         break
      i=GPIO.input(pidIn)
      count= count+1
      sumt= sumt+i
      if i==0:
         #print "No intruders",i
         GPIO.output(pidIndicator, 0)
         time.sleep(0.1)
      elif i==1:
         #print "Intruder detected",i
         GPIO.output(pidIndicator, 1)
         time.sleep(0.1)
   avg= float(sumt/count)
   templateData= {
      'moveInfo' : sumt
   }
   GPIO.output(pidIndicator, 0)

   return render_template('main.html', **templateData)

@app.route("/tvSignal")
def giveTvSignal():
   GPIO.output(TvSignal, GPIO.HIGH)
   GPIO.output(TvSignal, GPIO.LOW)

   templateData={
      'status' : "IR Signal Sent"
   }
   return render_template('main.html', **templateData)
   
if __name__ == "__main__":
   app.run(host='0.0.0.0', port=80, debug=True, threaded= True)
