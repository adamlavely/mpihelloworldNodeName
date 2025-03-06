# mpihelloworldNodeName

A quick hello world for MPI on CPUs that prints out the node name.

For including this into a Containerfile, make sure you have MPI installed and then add this using something like
# Install a test program
RUN git clone https://github.com/adamlavely/mpihelloworldNodeName.git

RUN cd mpihelloworldNodeName                      && \
    mpicc -o hello.out mpiHelloWorldNodeAndRank.c && \
    chmod 777 hello.out                           && \
    cp hello.out /usr/local/bin/.
