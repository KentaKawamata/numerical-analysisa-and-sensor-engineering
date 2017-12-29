import urllib
from readability.readability import Document
import html2text

url = urllib.request.urlopen('http://kids.yam.com/joke/article.php?cid=general&id=153411')

s = url.read()
article = Document(s).summary()
text = html2text.html2text(article)

print(text)
