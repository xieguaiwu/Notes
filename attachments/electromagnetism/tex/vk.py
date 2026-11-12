import json, urllib.request, base64, sys
auth = json.load(open('/home/wang/.pi/agent/auth.json'))
img = base64.b64encode(open('1112_q_graph_correct-1.png','rb').read()).decode()
body = {'model':'deepseek-v4-flash-vision-exp','max_tokens':6000,'messages':[{'role':'user','content':[
{'type':'text','text':'Quality-check this rendered TikZ graph (Charge vs Time). Answer briefly: 1) Does the curve start at origin with a FLAT horizontal tangent, rise to a single positive peak, and return to zero, never negative? 2) Are dashed guides at T/4, T/2, T positioned correctly (peak aligned with T/2)? 3) Any overlapping labels or cut-off text? 4) Usable as a textbook figure? List defects.'},
{'type':'image_url','image_url':{'url':'data:image/png;base64,'+img}}]}]}
req = urllib.request.Request('https://api.deepseek.com/chat/completions', data=json.dumps(body).encode(),
    headers={'Authorization':'Bearer '+auth['deepseek']['key'],'Content-Type':'application/json'})
r = urllib.request.urlopen(req, timeout=120)
data = json.loads(r.read())
open('vk_out.txt','w').write(data['choices'][0]['message']['content'])
