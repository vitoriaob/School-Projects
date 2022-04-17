import requests
from urllib.parse import urlparse
import http.client as httplib

host = '222.109.221.166'
port = 	58278
conn = httplib.HTTPConnection(host,port)

# Mission 1 - Header

url_string = 'http://34.64.159.33:62445/test/index.html'
url = urlparse(url_string)

user = '2020049061/VITORIAONGARATTOBALDAN/WEBCLIENT/COMPUTERNETWORK'
r1 = requests.get(url_string, headers={'User-Agent': user}, timeout=10)
print('Mission 1: true')



#Mission 2 - GET, Counting images

image_count = 0
null_count = 0
for body_line in r1.content.decode('utf8').split("\n"):
    if '<img id="image' in body_line:
        image_count += 1
        if 'null' in body_line:
            null_count += 1

image_count -= null_count

print('Mission 2: true ')
print('Number of images: %s' % image_count)


#Mission 3 - POST and number

post_url = "http://%s:%s/test/result.html" % (url.hostname, url.port)
r2 = requests.post(post_url, headers={'User-Agent': user}, timeout=10, data={
    "stuAnswer": image_count,
    "sno1": "2020049061"})
if'<h2 id = "sentPic"' in post_response_body and 'Correct:' in post_response_body:
    print('Mission 3: true')


r3 = requests.post('http://%s:%s/test/postHandleTest' % (url.hostname, url.port), data="2020049061",
                   headers={'User-Agent': user})

print('Mission 03: true')
print('Number: %s' % r3.content.decode())


#Mission 4 - GUI

r4 = requests.get('http://34.64.159.33:62397/test/262585.jpg', allow_redirects = True, headers={'User-Agent': user})
open('image.jpg','wb').write(r4.content)
print('Mission 4: true')

