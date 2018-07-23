#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include "particles.h"

using namespace std;


int main(int argc, char *argv[]) {

    if (argc != 3) { /* 2 arguments */
        cout << " usage : ./physics M N \nwhere M is the number of particles that will be created ";
        cout << "and N is the total number of loops for interactions and decays" << endl;
        return -1;
    }
    int M;
    M = atoi(argv[1]);
    if (M <= 1) {
        cout << "You need to create 2 or more particles" << endl;
        return -2;
    }
    int N;
    N = atoi(argv[2]);
    if (N <= 0) {
        cout << "Loop interval must be a positive integer" << endl;
        return -3;
    }

    /* initialize random seed: */
    srand(time(NULL));

    /* number of particles */
    int number_of_particles = M;
    int random_particle;
    /*vector of particles*/
    vector<Particle *> particle_matrix;
    // a matrix who stores  each particle's kind, the cells in the last two rows are used to store
    // the number of fermions and bosons

    int count_particle_number_matrix[NR_PARTICLES + 2];
    for (int i = 0; i < NR_PARTICLES + 2; i++) {
        count_particle_number_matrix[i] = 0;
    }

    //fill the vector with random particles
    cout << "\n************************Creating Particles************************ \n" << endl;
    for (int i = 0; i < number_of_particles; i++) {
        random_particle = rand() % NR_PARTICLES;
        particle_matrix.push_back(generate_particle(random_particle));
        *count_particle_number_matrix = count_particles(count_particle_number_matrix, particle_matrix[i]->getType(),
                                                        false);
    }
    cout << "\n************************Creating Particles************************ \n" << endl;

    int initial_number_of_fermions = count_particle_number_matrix[NR_PARTICLES];
    int initial_number_of_protons = count_particle_number_matrix[0];
    int initial_number_of_neutrons = count_particle_number_matrix[1];
    int initial_number_of_electrons = count_particle_number_matrix[2];
    int initial_number_of_positrons = count_particle_number_matrix[3];
    int initial_number_of_neutrinos = count_particle_number_matrix[4];
    int initial_number_of_antineutrinos = count_particle_number_matrix[5];
    int initial_number_of_bosons = count_particle_number_matrix[NR_PARTICLES + 1];
    int initial_number_of_photons = count_particle_number_matrix[6];

    int initial_total_electric_charge =
            initial_number_of_protons + initial_number_of_positrons - initial_number_of_electrons;
    double total_mass = count_mass(initial_number_of_protons, initial_number_of_neutrons, initial_number_of_electrons,
                                   initial_number_of_positrons, initial_number_of_neutrinos,
                                   initial_number_of_antineutrinos);
    double total_spin = count_spin(initial_number_of_fermions, initial_number_of_bosons);


    cout << "\n************************Interactions and Decays************************ \n" << endl;


    int random_particle_index, new_particles, previous_particles, next_index, previous_index, particle_1, particle_2;

    for (int i = 0; i < N; i++) {
        //choose a random index
        random_particle_index = rand() % number_of_particles;
        //make the vector a cycle vector
        next_index = (random_particle_index + 1) % number_of_particles;
        previous_index = (random_particle_index - 1) % number_of_particles;
        if (previous_index == -1) {
            previous_index = number_of_particles - 1;
        }
        // the particles the will be created from the interaction with the next particle in the vector
        new_particles = interactions(particle_matrix[random_particle_index]->getType(),
                                     particle_matrix[next_index]->getType());
        // the particles the will be created from the interaction with the previous particle in the vector
        previous_particles = interactions(particle_matrix[random_particle_index]->getType(),
                                          particle_matrix[previous_index]->getType());
        cout << "\n....Attempting interactions....\n" << endl;
        if (new_particles != -1) {
            cout << "....Doing next interaction....\n" << endl;
            //because we have created an interaction table according to the heptadic system we get the first particle
            //of the interactions if we divide the cell with the number 7 and the second particle using modulo  7
            particle_1 = new_particles / NR_PARTICLES;
            particle_2 = new_particles % NR_PARTICLES;
            //delete particle numbers
            *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                            particle_matrix[random_particle_index]->getType(), true);
            *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                            particle_matrix[next_index]->getType(), true);
            //delete particles
            delete (particle_matrix[random_particle_index]);
            delete (particle_matrix[next_index]);
            //generate two new particles to replace the old according to the interaction
            particle_matrix[random_particle_index] = generate_particle(particle_1);
            particle_matrix[next_index] = generate_particle(particle_2);
            //count them
            *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                            particle_matrix[random_particle_index]->getType(), false);
            *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                            particle_matrix[next_index]->getType(), false);
            continue;
        } else if (previous_particles != -1) {
            //same as before
            cout << "....Doing previous interaction....\n" << endl;
            particle_1 = previous_particles / NR_PARTICLES;
            particle_2 = previous_particles % NR_PARTICLES;
            *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                            particle_matrix[random_particle_index]->getType(), true);
            *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                            particle_matrix[previous_index]->getType(), true);
            delete (particle_matrix[random_particle_index]);
            delete (particle_matrix[previous_index]);
            particle_matrix[random_particle_index] = generate_particle(particle_1);
            particle_matrix[previous_index] = generate_particle(particle_2);
            *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                            particle_matrix[random_particle_index]->getType(), false);
            *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                            particle_matrix[previous_index]->getType(), false);
            continue;
        } else {
            cout << "....Attempting decays....\n" << endl;
            //doing decays
            if (particle_matrix[random_particle_index]->getType() == NEUTRON) {
                cout << "....Neutron decay....\n" << endl;
                //count deleted neutron
                *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                                particle_matrix[random_particle_index]->getType(),
                                                                true);
                delete (particle_matrix[random_particle_index]);
                // generate 3 new particles according to the decay
                particle_matrix[random_particle_index] = generate_particle(PROTON);
                particle_matrix.insert(particle_matrix.begin() + random_particle_index, generate_particle(ELECTRON));
                particle_matrix.insert(particle_matrix.begin() + random_particle_index + 1,
                                       generate_particle(ANTINEUTRINO));
                //count them
                *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                                particle_matrix[random_particle_index]->getType(),
                                                                false);
                *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                                particle_matrix[random_particle_index + 1]->getType(),
                                                                false);
                *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                                particle_matrix[random_particle_index + 2]->getType(),
                                                                false);
                // increase the number of particles by 2
                number_of_particles += 2;
                continue;
            } else if (particle_matrix[random_particle_index]->getType() == PROTON) {
                //same as neutron decay
                cout << "....Proton decay....\n" << endl;
                *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                                particle_matrix[random_particle_index]->getType(),
                                                                true);
                delete (particle_matrix[random_particle_index]);
                particle_matrix[random_particle_index] = generate_particle(NEUTRON);
                particle_matrix.insert(particle_matrix.begin() + random_particle_index, generate_particle(POSITRON));
                particle_matrix.insert(particle_matrix.begin() + random_particle_index + 1,
                                       generate_particle(NEUTRINO));
                *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                                particle_matrix[random_particle_index]->getType(),
                                                                false);
                *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                                particle_matrix[random_particle_index + 1]->getType(),
                                                                false);
                *count_particle_number_matrix = count_particles(count_particle_number_matrix,
                                                                particle_matrix[random_particle_index + 2]->getType(),
                                                                false);
                number_of_particles += 2;
                continue;
            }
        }
        cout << "No more possible interactions or decays\n" << endl;
    }
    cout << "\n************************Interactions and Decays************************ \n" << endl;

    //statistics of particles after the interactions and decays
    int final_number_of_fermions = count_particle_number_matrix[NR_PARTICLES];
    int final_number_of_protons = count_particle_number_matrix[0];
    int final_number_of_neutrons = count_particle_number_matrix[1];
    int final_number_of_electrons = count_particle_number_matrix[2];
    int final_number_of_positrons = count_particle_number_matrix[3];
    int final_number_of_neutrinos = count_particle_number_matrix[4];
    int final_number_of_antineutrinos = count_particle_number_matrix[5];
    int final_number_of_bosons = count_particle_number_matrix[NR_PARTICLES + 1];
    int final_number_of_photons = count_particle_number_matrix[6];

    int final_total_electric_charge = final_number_of_protons + final_number_of_positrons - final_number_of_electrons;
    double new_total_mass = count_mass(final_number_of_protons, final_number_of_neutrons, final_number_of_electrons,
                                       final_number_of_positrons, final_number_of_neutrinos,
                                       final_number_of_antineutrinos);
    double new_total_spin = count_spin(final_number_of_fermions, final_number_of_bosons);


    cout << "\n************************Destroying Particles************************ \n" << endl;
    //free memory
    for (int i = 0; i < number_of_particles; i++) {
        delete particle_matrix[i];
    }
    cout << "\n************************Destroying Particles************************ \n" << endl;

    //print statistics
    cout << "\n///////////////*********--First Statistics--***************///////////////\n" << endl;
    cout << "Number of fermions created ----> " << initial_number_of_fermions << endl;
    cout << "Number of protons created ----> " << initial_number_of_protons << endl;
    cout << "Number of neutrons created ----> " << initial_number_of_neutrons << endl;
    cout << "Number of electrons created ----> " << initial_number_of_electrons << endl;
    cout << "Number of positrons created ----> " << initial_number_of_positrons << endl;
    cout << "Number of neutrinos created ----> " << initial_number_of_neutrinos << endl;
    cout << "Number of antineutrinos created ----> " << initial_number_of_antineutrinos << endl;
    cout << "\nNumber of bosons created ----> " << initial_number_of_bosons << endl;
    cout << "Number of photons created ----> " << initial_number_of_photons << endl;
    cout << "\nTotal electric charge created ----> " << initial_total_electric_charge << endl;
    cout << setprecision(10) << "\nInitial total mass  created ----> " << total_mass << " mev/c^2" << endl;
    cout << setprecision(3) << "\nInitial total spin  created ----> " << total_spin << endl;
    cout << "\n///////////////*********--First Statistics--***************///////////////\n" << endl;


    cout << "\n///////////////*********--Final Statistics--***************///////////////\n" << endl;
    cout << "Number of fermions created ----> " << final_number_of_fermions << endl;
    cout << "Number of protons created ----> " << final_number_of_protons << endl;
    cout << "Number of neutrons created ----> " << final_number_of_neutrons << endl;
    cout << "Number of electrons created ----> " << final_number_of_electrons << endl;
    cout << "Number of positrons created ----> " << final_number_of_positrons << endl;
    cout << "Number of neutrinos created ----> " << final_number_of_neutrinos << endl;
    cout << "Number of antineutrinos created ----> " << final_number_of_antineutrinos << endl;
    cout << "\nNumber of bosons created ----> " << final_number_of_bosons << endl;
    cout << "Number of photons created ----> " << final_number_of_photons << endl;
    cout << "\nTotal electric charge created ----> " << final_total_electric_charge << endl;
    cout << setprecision(10) << "\nTotal mass  created ----> " << new_total_mass << " mev/c^2" << endl;
    cout << setprecision(3) << "\nTotal spin  created ----> " << new_total_spin << endl;
    cout << "\n///////////////*********--Final Statistics--***************///////////////\n" << endl;

    cout << "\n************************Percentages************************ \n" << endl;
    cout << setprecision(4) << "Proton change percentage ----> "
         << calculate_percentage(final_number_of_protons, initial_number_of_protons) << " % " << endl;
    cout << setprecision(4) << "Neutron change percentage ----> "
         << calculate_percentage(final_number_of_neutrons, initial_number_of_neutrons) << " % " << endl;
    cout << setprecision(4) << "Electron change percentage ----> "
         << calculate_percentage(final_number_of_electrons, initial_number_of_electrons) << " % " << endl;
    cout << setprecision(4) << "Positron change percentage ----> "
         << calculate_percentage(final_number_of_positrons, initial_number_of_positrons) << " % " << endl;
    cout << setprecision(4) << "Neutrino change percentage ----> "
         << calculate_percentage(final_number_of_neutrinos, initial_number_of_neutrinos) << " % " << endl;
    cout << setprecision(4) << "Antineutrino change percentage ----> "
         << calculate_percentage(final_number_of_antineutrinos, initial_number_of_antineutrinos) << " % " << endl;
    cout << setprecision(4) << "Photon change percentage ----> "
         << calculate_percentage(final_number_of_photons, initial_number_of_photons) << " % " << endl;
    cout << "\n************************Percentages************************ \n" << endl;


    double spin_difference = new_total_spin - total_spin;
    double mass_difference = new_total_mass - total_mass;

    cout << setprecision(10) << "Mass Difference is -------->" << mass_difference << " meV/c^2" << endl;
    cout << setprecision(3) << "Spin Difference is -------->" << spin_difference << endl;

    if ((spin_difference != 0) or (mass_difference != 0) ){
        cout << "\n\n=========== How it comes! ===========\n\n" << endl;
    }

    if (final_number_of_fermions > final_number_of_bosons) {
        cout << "\n\n=========== Living in a material word! ===========\n\n" << endl;
    } else if (final_number_of_fermions < final_number_of_bosons) {
        cout << "\n\n=========== Radiation prevails! ===========\n\n" << endl;
    } else {
        cout << "\n\n=========== Equilibrium? ===========\n\n" << endl;
    }

    if (initial_total_electric_charge == final_total_electric_charge) {
        cout << "\n\n=========== Conservation verified! ===========\n\n" << endl;
    }

    return 0;
}
