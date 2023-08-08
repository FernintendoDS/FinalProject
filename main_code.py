import AM
import AL
import re

def extract_data(d):
    pattern = r"U2 (\d+)"
    match = re.search(pattern, d)
    if match:
        u1_match = match.group(1)

        return u1_match
        
    else:
        return 
    
def mainnew():
    while True:
        d = AL.get_ultrasonic_back()
        dataU1 = extract_data(d)
        print(dataU1)

mainnew()
