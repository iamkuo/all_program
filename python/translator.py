"""
import googletrans
trans = googletrans.Translator()
results = trans.translate(input('enter the thing you want to translate'),dest=input('what language do you want to translate?'+str(googletrans.LANGCODES)))
print(results.text)
"""
import googletrans
from pprint import pprint


# Initial
translator = googletrans.Translator()


# Basic Translate
results = translator.translate('我覺得今天天氣不好。')
print(results)
print(results.text)
