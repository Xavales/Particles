//
// Created by bouzioto on 3/1/2017.
//

#ifndef PARTICLES_H
#define PARTICLES_H

#include <iostream>
#include <cstring>

#define NR_PARTICLES 7

enum particles {
    PROTON = 0, NEUTRON, ELECTRON, POSITRON, NEUTRINO, ANTINEUTRINO, PHOTON, UNKNOWN
};

using namespace std;

class Particle {

public:
    Particle();

    virtual ~Particle();

    virtual void PrintElem();

    virtual int getType() const;

    int getElectricCharge() const;

    double getMass() const;

    float getSpin() const;


protected:
    double mass;
    float spin;
    int electric_charge;
    string statistics;
};

class Fermion : public Particle {

public:
    Fermion();

    virtual ~Fermion();

    virtual void PrintElem();

    virtual int getType() const;

};

class Boson : public Particle {

public:
    Boson();

    virtual ~Boson();

    virtual void PrintElem();

    virtual int getType() const;

};

class Proton : public Fermion {

public:
    Proton();

    virtual ~Proton();

    virtual void PrintElem();

    virtual int getType() const;

};

class Neutron : public Fermion {

public:
    Neutron();

    virtual ~Neutron();

    virtual void PrintElem();

    virtual int getType() const;

};

class Electron : public Fermion {

public:
    Electron();

    virtual ~Electron();

    virtual void PrintElem();

    virtual int getType() const;

};

class Positron : public Fermion {

public:
    Positron();

    virtual ~Positron();

    virtual void PrintElem();

    virtual int getType() const;

};

class Neutrino : public Fermion {

public:
    Neutrino();

    virtual ~Neutrino();

    virtual void PrintElem();

    virtual int getType() const;

};

class AntiNeutrino : public Fermion {

public:
    AntiNeutrino();

    virtual ~AntiNeutrino();

    virtual void PrintElem();

    virtual int getType() const;

};

class Photon : public Boson {

public:
    Photon();

    virtual ~Photon();

    virtual void PrintElem();

    virtual int getType() const;

};

Particle *generate_particle(int particle_type);

int count_particles(int *count_particle_number_matrix, int particle_type, bool operation);

int interactions(int particle_1, int particle_2);

double count_mass(int number_of_protons, int number_of_neutrons, int number_of_electrons, int number_of_positrons,
                  int number_of_neutrinos, int number_of_antineutrinos);

double count_spin(int number_of_fermions, int number_of_bosons);

float calculate_percentage(int total_particle_number, int initial_particle_number);

#endif //PARTICLES_H
