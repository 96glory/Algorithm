import requests
import json

url = "https://swapi.dev/api/people/1/"
data = requests.get(url).json()
print(data)
jsonArray = data.get("films")
for ele in jsonArray:
    print(ele)

# kakao_url = "https://dapi.kakao.com/v2/search/web"
# queryString = {"query" : "류현진"}
# header = {'authorization' : 'KakaoAK [REST API 키]'}
# r = requests.get(url, headers = header, params=queryString)
# print(json.loads(r.text))