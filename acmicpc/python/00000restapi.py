import requests
import json

# url = "https://httpbin.org/get"
# data = requests.get(url).json()
# print(data)
# jsonArray = data.get("films")
# for ele in jsonArray:
#    print(ele)

# get json from REST API
url = "https://swapi.dev/api/people/1/"
data = requests.get(url).json()
print(type(data))
print(data)

# dictionary -> json (str)
json_data = json.dumps(data)
print(type(json_data))
print(json_data)

# pretty print
json_pretty_data = json.dumps(data, indent=2)
print(type(json_pretty_data))
print(json_pretty_data)

# json -> dictionary
dict_data = json.loads(json_data)
print(type(dict_data))
print(dict_data)

for i in range(len(data["vehicles"])):
    print(data["vehicles"][i])

# kakao_url = "https://dapi.kakao.com/v2/search/web"
# queryString = {"query" : "류현진"}
# header = {'authorization' : 'KakaoAK [REST API 키]'}
# r = requests.get(url, headers = header, params=queryString)
# print(json.loads(r.text))