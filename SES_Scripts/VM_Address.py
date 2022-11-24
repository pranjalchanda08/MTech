import math
import os
import sys

# All sizes are in Byte units

Vm = 64 * 1024      # Virtual Memory; Also known as ROM Size
Pm = 8 * 1024       # Physical Memory; Also Known as RAM Size
Cm = 512             # Cache Memory
Ps = 512          # Page Size
Ws = 2               # Word Size in bytes
Bs = Ws * 4              # Block Size

def get_pow_of_2(Size):
    return math.log10(Size) / math.log10(2)

AddrVm = get_pow_of_2(Vm)
AddrPm = get_pow_of_2(Pm)
AddrCm = get_pow_of_2(Cm)
AddrPs = get_pow_of_2(Ps)
AddrBs = get_pow_of_2(Bs)
if sys.platform == "win32":
    os.system('cls')
else:
    os.system("clear")
print("--------------------------------------------------")
print(f"Number of Pages in ROM\t\t:{Vm//Ps}")
print(f"Number of Pages in RAM\t\t:{Pm//Ps}")
print(f"No of Blocks in Cache\t\t:{Cm//Bs}")
print("--------------------------------------------------")
print(f"No of Bits (Cache)\t\t:{int(AddrCm)}")
print(f"No of Bits (Block)\t\t:{int(get_pow_of_2(Bs))}")
print(f"No of Bits (Block Offset)\t:{int(AddrCm - AddrBs)}")
print(f"No of Bits (TAG)\t\t:{int(AddrVm - AddrCm)}")
print(f"No of Bits (PPN)\t\t:{int(get_pow_of_2(Pm//Ps))}")
print(f"No of Bits (VPN)\t\t:{int(get_pow_of_2(Vm//Ps))}")
print(f"No of Bits (Page)\t\t:{int(AddrPs)}")
print(f"No of Bits (Pm / RAM)\t\t:{int(AddrPm)}")
print(f"No of Bits (Vm / ROM)\t\t:{int(AddrVm)}")
print("--------------------------------------------------")