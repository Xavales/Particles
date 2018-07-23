# Particles
A program which simulates the way particles from Physics interact which each other.

## Description
Consider a particle world that simplifies their characteristics and behavior in relation to their scientific version of Particle Physics. Specifically, assume that the following are valid:

* Each particle has mass, spin, and electric charge .If there is no indication of something different, they are 0. Depending on the statistics they follow, they are distinguished in fermions and bosons. The fermionsfollow Fermi-Dirac statistics. The bosons follow the Bose-Einstein statistic.

* A proton is a fermion and has a mass of 938.27208 MeV/c^2, spin equal to 0.5 and an electrical charge equal to +1. When a proton is created, is has assigned the value of its mass, its spin and its electric charge. Also, the message "A proton has been constructed" and the statistics it follows are printed. When a proton is destroyed, the message "A proton will be destroyed " is printed.

* A neutron is a fermion and has a mass of 939.56541 MeV/c^2, spin equal to 0.5. When a neutron is created, is has assigned the value of its mass, its spin and its electric charge. Also, the message "A neutron has been constructed" and the statistics it follows are printed. When a neutron is destroyed, the message "A neutron will be destroyed " is printed.

* An electron is a fermion and has a mass of 0.510998946 MeV/c^2, spin equal to 0.5 and an electrical charge equal to -1. When an electron is created, is has assigned the value of its mass, its spin and its electric charge. Also, the message "An electron has been constructed" and the statistics it follows are printed. When an electron is destroyed, the message "An electron will be destroyed " is printed.

* A positron is a fermion and has a mass of 0.510998946 MeV/c^2, spin equal to 0.5 and an electrical charge equal to +1. When a positron is created, is has assigned the value of its mass, its spin and its electric charge. Also, the message "A positron has been constructed" and the statistics it follows are printed. When a positron is destroyed, the message "A positron will be destroyed " is printed.

* A neutrino is a fermion and has a mass of 0.320 MeV/c^2, spin equal to 0.5. When a neutrino is created, is has assigned the value of its mass, its spin and its electric charge. Also, the message "A neutrino has been constructed" and the statistics it follows are printed. When a neutrino is destroyed, the message "A neutrino will be destroyed " is printed.

* An antineutrino has the exact same characteristics with the neutrino. When an antineutrino is created, is has assigned the value of its mass, its spin and its electric charge. Also, the message "An antineutrino has been constructed" and the statistics it follows are printed. When an antineutrino is destroyed, the message "An antineutrino will be destroyed " is printed.

* A photon is a boson and has a spin equal to 1. When a photon is created, is has assigned the value of its mass, its spin and its electric charge. Also, the message "A photon has been constructed" and the statistics it follows are printed. When a photon is destroyed, the message "A photon will be destroyed " is printed.

### Particle Interactions

Among the above particles the following interactions may take place:

* from neutron and neutrino, proton and electron arise
* from proton and antineutrino, arises neutron and positron
* from proton and electron, neutrons and neutrinos arise
* an electron is mutually displaced with a positron producing two photons
* from two photons an electron and a positron can be produced

Also, the following decays may occur:

* a neutron decays to produce a proton, an electron and an antineutrino
* a proton decays to produce a neutron, a positron and a neutrino


## Program flow and usage

1. M number of particles are created,  which are accessed through an M sequence by randomly choosing their type.

2. The number of each kind of particle created and the total electric charge created is printed.

3. For N loops, a particle is randomly selected and if it can interact
with one of its neighbors, an interaction is made, otherwise if it can be broken up,
it decays. As "adjacent" are considered particles that are accessed through successive
indications.

4. The amount of each kind of particle that eventually exists as well as the
percentage change of particles relative to their original number is printed. Also, if the amount of
fermions is larger than that of the bosons the message "Living
in a material world! " is printed, otherwise, if the reverse is true, the message
"Radiation prevailed! " is printed. Otherwise,"Equilibrium?" message is printed. Moreover, it is confirmed that the total electric
charge of particles is conserved and the message "Conservation verified!" is printed. Finally, the difference in the sum of the mass of the particles and the difference in the sum of the spin of the particles is calculated and printed,
and if one of them is different from zero, the message "How it comes!" is printed. 

5. M and N parameters are given by the user from stdin.


### Compilation 

Assuming that all the source files are in the same directory, the program is compiled by a simple ``` make ``` command and the 
*physics* executable file is produced.

#### Example usage

``` ./physics M N ``` where M and N are the parameters mentioned in the [program flow and usage](#program-flow-and-usage) section 













