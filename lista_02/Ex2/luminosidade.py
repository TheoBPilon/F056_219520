import re

with open("brilcalc.log","r") as f:
    text = f.read() # apenas le o .log como texto

                  #1           #2           #3          #4             #5              #6
padrao = r"\|\s*(\d+)\s*\|\s*(\d+)\s*\|\s*(\d+)\s*\|\s*(\d+)\s*\|\s*([\d.]+)\s*\|\s*([\d.]+)\s*\|"
result = re.search(padrao,text) # procura no texto algo que segue o 'padrao'
recorded_pb = float(result.group(6)) # fala p ele pegar a sexta coluna dessa parte
recorded_fb = recorded_pb/1000


print(f"Luminosidade integrada recorded: {recorded_fb:.1f} fb^-1")
