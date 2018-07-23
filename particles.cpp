//
// Created by bouzioto on 3/1/2017.
//

#include "particles.h"
#include <cstdlib>
//class functions

Particle::Particle() {
    this->mass = 0;
    this->spin = 0;
    this->electric_charge = 0;
    this->statistics = "Unknown";
//    cout << "A particle has been constructed" << endl;
}

void Particle::PrintElem() {
    cout << "Particle mass is " << this->mass << endl;
    cout << "Particle spin is " << this->spin << endl;
    cout << "Particle electric charge is " << this->electric_charge << endl;
    cout << "Particle statistics is " << this->statistics << endl;
}

int Particle::getType() const {
    return 0;
}

int Particle::getElectricCharge() const {
    return this->electric_charge;
}

double Particle::getMass() const {
    return this->mass;
}

float Particle::getSpin() const {
    return this->spin;
}

Particle::~Particle() {
//    cout << "A particle has been destroyed" << endl;
}


Fermion::Fermion() : Particle() {
    this->statistics = "Fermi-Dirac";
//    cout << "A fermion has been constructed" << endl;
}

void Fermion::PrintElem() {
    cout << "Fermion mass is " << this->mass << endl;
    cout << "Fermion spin is " << this->spin << endl;
    cout << "Fermion electric charge is " << this->electric_charge << endl;
    cout << "Fermion statistics is " << this->statistics << endl;
}

int Fermion::getType() const {
    return 0;
}

Fermion::~Fermion() {
//    cout << "A fermion has been destroyed" << endl;
}

Boson::Boson() : Particle() {
    this->statistics = "Bose-Einstein";
//    cout << "A boson has been constructed" << endl;
}

void Boson::PrintElem() {
    cout << "Boson mass is " << this->mass << endl;
    cout << "Boson spin is " << this->spin << endl;
    cout << "Boson electric charge is " << this->electric_charge << endl;
    cout << "Boson statistics is " << this->statistics << endl;
}

int Boson::getType() const {
    return 0;
}

Boson::~Boson() {
//    cout << "A boson has been destroyed" << endl;
}

Proton::Proton() : Fermion() {
    this->mass = 938.27208;
    this->spin = 0.5;
    this->electric_charge = 1;
    cout << "A proton has been constructed" << endl;
}

void Proton::PrintElem() {
    cout << "Proton mass is " << this->mass << endl;
    cout << "Proton spin is " << this->spin << endl;
    cout << "Proton electric charge is " << this->electric_charge << endl;
    cout << "Proton statistics is " << this->statistics << endl;
}

int Proton::getType() const {
    return PROTON;
}


Proton::~Proton() {
    cout << "A proton has been destroyed" << endl;
}

Neutron::Neutron() : Fermion() {
    this->mass = 939.56542;
    this->spin = 0.5;
    cout << "A neutron has been constructed" << endl;
}

void Neutron::PrintElem() {
    cout << "Neutron mass is " << this->mass << endl;
    cout << "Neutron spin is " << this->spin << endl;
    cout << "Neutron electric charge is " << this->electric_charge << endl;
    cout << "Neutron statistics is " << this->statistics << endl;
}

int Neutron::getType() const {
    return NEUTRON;
}

Neutron::~Neutron() {
    cout << "A neutron has been destroyed" << endl;
}

Electron::Electron() : Fermion() {
    this->mass = 0.510998946;
    this->spin = 0.5;
    this->electric_charge = -1;
    cout << "An electron has been constructed" << endl;
}

void Electron::PrintElem() {
    cout << "Electron mass is " << this->mass << endl;
    cout << "Electron spin is " << this->spin << endl;
    cout << "Electron electric charge is " << this->electric_charge << endl;
    cout << "Electron statistics is " << this->statistics << endl;
}

int Electron::getType() const {
    return ELECTRON;
}

Electron::~Electron() {
    cout << "An electron has been destroyed" << endl;
}

Positron::Positron() : Fermion() {
    this->mass = 0.510998946;
    this->spin = 0.5;
    this->electric_charge = 1;
    cout << "A positron has been constructed" << endl;
}

void Positron::PrintElem() {
    cout << "Positron mass is " << this->mass << endl;
    cout << "Positron spin is " << this->spin << endl;
    cout << "Positron electric charge is " << this->electric_charge << endl;
    cout << "Positron statistics is " << this->statistics << endl;
}

int Positron::getType() const {
    return POSITRON;
}

Positron::~Positron() {
    cout << "A positron has been destroyed" << endl;
}

Neutrino::Neutrino() : Fermion() {
    this->mass = 320;
    this->spin = 0.5;
    cout << "A neutrino has been constructed" << endl;
}

void Neutrino::PrintElem() {
    cout << "Neutrino mass is " << this->mass << endl;
    cout << "Neutrino spin is " << this->spin << endl;
    cout << "Neutrino electric charge is " << this->electric_charge << endl;
    cout << "Neutrino statistics is " << this->statistics << endl;
}

int Neutrino::getType() const {
    return NEUTRINO;
}

Neutrino::~Neutrino() {
    cout << "A neutrino has been destroyed" << endl;
}

AntiNeutrino::AntiNeutrino() : Fermion() {
    this->mass = 320;
    this->spin = 0.5;
    cout << "An antineutrino has been constructed" << endl;
}

void AntiNeutrino::PrintElem() {
    cout << "Antineutrino mass is " << this->mass << endl;
    cout << "Antineutrino spin is " << this->spin << endl;
    cout << "Antineutrino electric charge is " << this->electric_charge << endl;
    cout << "Antineutrino statistics is " << this->statistics << endl;
}

int AntiNeutrino::getType() const {
    return ANTINEUTRINO;
}

AntiNeutrino::~AntiNeutrino() {
    cout << "An antineutrino has been destroyed" << endl;
}

Photon::Photon() : Boson() {
    this->spin = 1;
    cout << "A photon has been constructed" << endl;
}

void Photon::PrintElem() {
    cout << "Photon mass is " << this->mass << endl;
    cout << "Photon spin is " << this->spin << endl;
    cout << "Photon electric charge is " << this->electric_charge << endl;
    cout << "Photon statistics is " << this->statistics << endl;
}

int Photon::getType() const {
    return PHOTON;
}

Photon::~Photon() {
    cout << "A photon has been destroyed" << endl;
}

//counts total mass of particles
double count_mass(int number_of_protons, int number_of_neutrons, int number_of_electrons,
                  int number_of_positrons, int number_of_neutrinos, int number_of_antineutrinos) {
    double total_mass = (number_of_antineutrinos + number_of_neutrinos) * 320 +
                        (number_of_electrons + number_of_positrons) * 0.510998946 + number_of_protons * 938.27208 +
                        number_of_neutrons * 939.56542;
    return total_mass;
}

//calculates the percentage change between the initial particle number and the total particle number
float calculate_percentage(int total_particle_number, int initial_particle_number) {
    if (initial_particle_number != 0) {
        int temp = abs(total_particle_number - initial_particle_number);
        float percentage = (((float) temp / (float) initial_particle_number)) * 100;
        return percentage;
    } else
        return 0;
}
//counts total spin of particles
double count_spin(int number_of_fermions, int number_of_bosons) {
    double total_spin = number_of_fermions * 0.5 + number_of_bosons;
    return total_spin;
}

//returns a pointer to a particle according to the enum , throws error if particle_type is unknown
Particle *generate_particle(int particle_type) {

    Particle *ptr;
    switch (particle_type) {
        case PROTON: {
            ptr = new Proton;
            break;
        }
        case NEUTRON: {
            ptr = new Neutron;
            break;
        }
        case ELECTRON: {
            ptr = new Electron;
            break;
        }
        case POSITRON: {
            ptr = new Positron;
            break;
        }
        case NEUTRINO: {
            ptr = new Neutrino;
            break;
        }
        case ANTINEUTRINO: {
            ptr = new AntiNeutrino;
            break;
        }
        case PHOTON: {
            ptr = new Photon;
            break;
        }

        default: {
            cout << "Unknown particle found" << endl;
            throw UNKNOWN;
        }

    }
    return ptr;
}

//counts the total number of each particle, along with the number of fermions and bosons
//the operation flag indicates subtraction if it is true, addition if it is false
int count_particles(int *count_particle_number_matrix, int particle_type, bool operation) {

    if (!operation) {
        switch (particle_type) {
            case PROTON: {
                count_particle_number_matrix[particle_type]++;
                count_particle_number_matrix[NR_PARTICLES]++;
                break;
            }
            case NEUTRON: {
                count_particle_number_matrix[particle_type]++;
                count_particle_number_matrix[NR_PARTICLES]++;
                break;
            }
            case ELECTRON: {
                count_particle_number_matrix[particle_type]++;
                count_particle_number_matrix[NR_PARTICLES]++;
                break;
            }
            case POSITRON: {
                count_particle_number_matrix[particle_type]++;
                count_particle_number_matrix[NR_PARTICLES]++;
                break;
            }
            case NEUTRINO: {
                count_particle_number_matrix[particle_type]++;
                count_particle_number_matrix[NR_PARTICLES]++;
                break;
            }
            case ANTINEUTRINO: {
                count_particle_number_matrix[particle_type]++;
                count_particle_number_matrix[NR_PARTICLES]++;
                break;
            }
            case PHOTON: {
                count_particle_number_matrix[particle_type]++;
                count_particle_number_matrix[NR_PARTICLES + 1]++;
                break;
            }

            default: {
                cout << "Unknown particle" << endl;
                throw UNKNOWN;
            }

        }

        return *count_particle_number_matrix;
    } else {
        switch (particle_type) {
            case PROTON: {
                count_particle_number_matrix[particle_type]--;
                count_particle_number_matrix[NR_PARTICLES]--;
                break;
            }
            case NEUTRON: {
                count_particle_number_matrix[particle_type]--;
                count_particle_number_matrix[NR_PARTICLES]--;
                break;
            }
            case ELECTRON: {
                count_particle_number_matrix[particle_type]--;
                count_particle_number_matrix[NR_PARTICLES]--;
                break;
            }
            case POSITRON: {
                count_particle_number_matrix[particle_type]--;
                count_particle_number_matrix[NR_PARTICLES]--;
                break;
            }
            case NEUTRINO: {
                count_particle_number_matrix[particle_type]--;
                count_particle_number_matrix[NR_PARTICLES]--;
                break;
            }
            case ANTINEUTRINO: {
                count_particle_number_matrix[particle_type]--;
                count_particle_number_matrix[NR_PARTICLES]--;
                break;
            }
            case PHOTON: {
                count_particle_number_matrix[particle_type]--;
                count_particle_number_matrix[NR_PARTICLES + 1]--;
                break;
            }

            default: {
                cout << "Unknown particle" << endl;
                throw UNKNOWN;
            }

        }

        return *count_particle_number_matrix;
    }
}

// interaction table in the heptadic system
// each cell represents a possible interaction between 2 particles or is -1 if they do not interact
// the cell number divided by 7 gives the first particle from the result of the interaction whereas using modulo 7
// gives the the second one
int interactions(int particle_1, int particle_2) {
    static int INTERACTIONS[NR_PARTICLES][NR_PARTICLES], visited = 0;
    if (!visited) {
        visited = 1;
        for (int i = 0; i < NR_PARTICLES; i++)
            for (int j = 0; j < NR_PARTICLES; j++)
                INTERACTIONS[i][j] = -1;
        INTERACTIONS[NEUTRON][NEUTRINO] = PROTON * NR_PARTICLES + ELECTRON;
        INTERACTIONS[NEUTRINO][NEUTRON] = PROTON * NR_PARTICLES + ELECTRON;
        INTERACTIONS[PROTON][ANTINEUTRINO] = NEUTRON * NR_PARTICLES + POSITRON;
        INTERACTIONS[ANTINEUTRINO][PROTON] = NEUTRON * NR_PARTICLES + POSITRON;
        INTERACTIONS[PROTON][ELECTRON] = NEUTRON * NR_PARTICLES + NEUTRINO;
        INTERACTIONS[ELECTRON][PROTON] = NEUTRON * NR_PARTICLES + NEUTRINO;
        INTERACTIONS[ELECTRON][POSITRON] = PHOTON * NR_PARTICLES + PHOTON;
        INTERACTIONS[POSITRON][ELECTRON] = PHOTON * NR_PARTICLES + PHOTON;
        INTERACTIONS[PHOTON][PHOTON] = ELECTRON * NR_PARTICLES + POSITRON;
    }

    return INTERACTIONS[particle_1][particle_2];
}
