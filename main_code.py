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
        d = AL.get_ultrasonic_back1()
        dataU1 = extract_data(d, "U1")
        print("U1 "+dataU1)
        b = AL.get_ultrasonic_back2()
        dataU2 = extract_data(b, "U2")
        print("U2 "+dataU2)
        c = AL.get_ultrasonic_back3()
        dataU3 = extract_data(c, "U3")
        print("U3 "+dataU3)
       
mainnew()
