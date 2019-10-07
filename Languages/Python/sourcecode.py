import urllib.request
request_url = urllib.request.urlopen('https://github.com/acmbvp/Hacktoberfest') #To open url
data=request_url.read() #To read HTML
print (data)
