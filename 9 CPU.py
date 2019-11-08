import errno, os, winreg
from ctypes import *
val = c_int64()
windll.Kernel32.QueryPerformanceCounter(byref(val))
print(val.value)

val2 = c_int64()
windll.Kernel32.QueryPerformanceFrequency(byref(val2))
print(val2.value)