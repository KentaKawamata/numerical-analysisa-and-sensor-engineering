import urllib
from readability.readability import Document
import html2text

url = urllib.request.urlopen('https://www.gutenberg.org/files/56191/56191-h/56191-h.htm')

s = url.read()
article = Document(s).summary()
text = html2text.html2text(article)

#アルファベット,改行,スペース以外全部削除
for i in range(len(text)):
    
    if text[i].isalpha()==False:
        if text[i] != "\n":
            str = text[i]
            text = text.replace(str, "_")

text = text.lower()    

#text = text.encode('utf-8')
#text = text.decode('ascii')

fp = open('usethisfile.txt', 'w')
fp.write(text)
fp.close()
