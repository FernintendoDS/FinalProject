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
        dataUBL = extract_data(d, "UBL")
        print("UB1 "+dataUBL)
        dataUBM = extract_data(d, "UBM")
        print("UB2 "+dataUBM)
        dataUBR = extract_data(d, "UBR")
        print("UB3 "+dataUBR)
       
mainnew()
