import win32file
import os
def get_drivestats(drive=None):
    '''
    drive for instance 'C'
    returns total_space, free_space and drive letter
    '''
    # if no drive given, pick the current working directory's drive
    if drive == None:
        drive = os.path.splitdrive(os.getcwd())[0].rstrip(':')
    sectPerCluster, bytesPerSector, freeClusters, totalClusters = \
        win32file.GetDiskFreeSpace(drive + ":\\")
    total_space = totalClusters*sectPerCluster*bytesPerSector
    free_space = freeClusters*sectPerCluster*bytesPerSector
    return total_space, free_space, drive
# use default drive (current drive)
# or specify drive for instance C --> get_drivestats('C')
total_space, free_space, drive = get_drivestats()
print( "Drive = %s" % drive )
print( "total_space = %d bytes" % total_space )
print( "free_space  = %d bytes" % free_space )
print( "used_space  = %d bytes" % (total_space - free_space) )
print( '-'*40 )
mb = float(1024 * 1024)  # float() needed for Python2
print( "Drive = %s" % drive )
print( "total_space = %0.2f Mb" % (total_space/mb) )
print( "free_space  = %0.2f Mb" % (free_space/mb) )
print( "used_space  = %0.2f Mb" % ((total_space - free_space)/mb) )
print( '-'*40 )
gb = float(1024 * 1024 * 1024)
print( "Drive = %s" % drive )
print( "total_space = %0.2f Gb" % (total_space/gb) )
print( "free_space  = %0.2f Gb" % (free_space/gb) )
print( "used_space  = %0.2f Gb" % ((total_space - free_space)/gb) )