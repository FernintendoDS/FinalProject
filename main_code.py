import AM
import AL
import re

def extract_data(d, tag):
    pattern = fr"{tag} (\d+)"
    match = re.search(pattern, d)
    if match:
        match = match.group(1)

        return match
    else:
        return 

    
def mainnew():
    while True:
        d = AL.get_ultrasonic_back()
        dataUB1 = extract_data(d, "UB1")
        print("UB1 "+dataUB1)
        dataUB2 = extract_data(d, "UB2")
        print("UB2 "+dataUB2)
        dataUB3 = extract_data(d, "UB3")
        print("UB3 "+dataUB3)
       
mainnew()
