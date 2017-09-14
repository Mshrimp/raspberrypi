import requests
import re

url_forum = 'http://tieba.baidu.com/i/244792107/forum'

r2 = requests.get(url_forum)
search = re.findall(ur'forum_name":"(.+?)''',r2.txt)
num_forum = len(search)
print num_forum

num = 0
num_error = 0
ok_num = 0
error_num = 0


Cookie = '244792107'
headers = {
'Accept':'application/json, text/javascript, */*; q=0.01',
'Accept-Encoding':'gzip, deflate',
'Accept-Language':'zh-CN,zh;q=0.8,en;q=0.6',
'Connection':'keep-alive',
'Content-Length':'61',
'Content-Type':'application/x-www-form-urlencoded; charset=UTF-8',
'Cookie':Cookie,
'DNT':'1',
'Host':'tieba.baidu.com',
'Origin':'http://tieba.baidu.com',
'User-Agent':'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.130 Safari/537.36',
'X-Requested-With':'XMLHttpRequest',
}
pid = True
while num != num_forum and pid:
    for i in search:
        payload = {'ie':'utf-8','kw':i,'tbs':'fb6ecec1996df5d41435580832'}
        r = requests.post('http://tieba.baidu.com/sign/add', data=payload, headers=headers, timeout=3)
        html = r.text.decode('raw_unicode_escape')
        ## print i, html
    #if html == u'{"no":1101,"error":"亲，你之前已经签过了","data":""}':
    if html == '{"no":1101,"error":"亲，你之前已经签过了","data":""}':
        ok_num += 1
    print ok_num


if ok_num == num_forum:
    pid = False
else:
    error_num += 1
if error_num == 5:
    pid = False


