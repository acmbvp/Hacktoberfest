import os

import pyttsx3
 
pyttsx3.speak("hello how may i help you sir")

while True:

  pyttsx3.speak("Enter cmnd u want me to open")

  a=input("Enter cmnd u want me to run:")

  print(a)

  b=a.lower()

  if ("run" in b) and("chrome" in b):

    os.system("start chrome")

    pyttsx3.speak("opening please wait")

  elif ("run" in b) and ("vlc" in b):

    os.system("start vlc")

    pyttsx3.speak("opening please wait")

  elif ("run" in b) and ("notepad" in b):

    os.system("start notepad")

    pyttsx3.speak("opening please wait")

  elif ("run" in b) and ("wordpad" in b):

    os.system("start wordpad")

    pyttsx3.speak("opening please wait")

  elif ("run" in b) and ("wmplayer" in b):

    os.system("start wmplayer")

    pyttsx3.speak("opening please wait")

  elif ("run" in b ) and ("mspaint" in b):

    os.system("start mspaint")

    pyttsx3.speak("opening please wait")

  elif ("run" in b) and ("excel" in b):

    os.system("start excel")

    pyttsx3.speak("opening please wait")

  elif("hey" in b) and (("quit" in b) or ("bye" in b)):

    pyttsx3.speak("exiting please wait hope you like my service see u soon ")

    break
