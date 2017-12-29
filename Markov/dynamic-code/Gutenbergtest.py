import urllib
from readability.readability import Document
import html2text

url = urllib.request.urlopen('https://www.gutenberg.org/files/56191/56191-h/56191-h.htm')

s = url.read()
article = Document(s).summary()
text = html2text.html2text(article)

text = text.encode('utf-8')
text = text.decode('ascii')
#print(text)

fp = open('Gutenberg.txt', 'w')
fp.write(text)
fp.close()
