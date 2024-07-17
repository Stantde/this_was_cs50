'''
1 say

engine = pyttsx4.init()
engine.say('this is an english text to voice test.')
engine.runAndWait()
2 save to file

import pyttsx4

engine = pyttsx4.init()
engine.save_to_file('i am Hello World, i am a programmer. i think life is short.', 'test1.wav')
engine.runAndWait()
'''
import pyttsx4

#read text into memory then say each line
text_to_read = []
engine = pyttsx4.init()
with open("text.txt", encoding="utf-8") as f:
    for _ in f:
        text_to_read.append(_)
        #engine.say(_)
        #engine.runAndWait()

#engine.save_to_file(text_to_read,'text.wav')
#engine.runAndWait()
