# DISCLAIMER

**THE AUTHORS OF THIS SOFTWARE ACCEPT ABSOLUTELY NO LIABILITY FOR ANY HARM OR LOSS RESULTING FROM ITS USE.
IT IS _EXTREMELY_ UNWISE TO RELY ON SOFTWARE ALONE FOR SAFETY.
Any machinery capable of harming persons must have provisions for completely removing power from all motors, etc, before persons enter any danger area.
All machinery must be designed to comply with local and national safety codes, and the authors of this software can not, and do not, take any responsibility for such compliance.**


This software is released under the GPLv2, with some parts under the LGPL.
See the file COPYING for more details.


# The Build Process

Refer to the file 'docs/INSTALL' for information about building and 
running the software.
    

# Quickstart

From the top level directory, switch to the source directory:

    cd src

In the source directory, build LinuxCNC:

    # for rtai
    ./autogen.sh
    ./configure
    # or, for PREEMPT-rt or vanilla kernels:
    ./autogen.sh
    ./configure --with-realtime=uspace

    make clean
    make
    # for rtai or PREEMPT-rt kernels:
    sudo make setuid

to run the software go back to the top level directory, and issue:

    . scripts/rip-environment
    linuxcnc
