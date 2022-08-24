#ifndef PROCESSES_H
#define PROCESSES_H

#include <string>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

#include "Grains.h"
#include "Polycrystals.h"
#include "Toolbox.h"

namespace Procs{

class Process
{
    private:
        Matrix3d Udot_input; //the velocity gradient in process file
        Matrix3d Ddot_input; //the strain rate calculated by the velocity gradient in process file
        Matrix3d Sdot_input; //the stress tensor in process file

        Matrix3i IUdot; //the flag of known (control by Udot_input) and unknown (calculated by EVPSC) velocity components
        Vector6i IDdot; //the flag of known and unknown strain rate components
        Vector6i ISdot; //the flag of known and unknown stress componets

        double Eincr; //the increment of strain in every istep
        int Ictrl;
        int Nsteps; // total steps
        double Temp; // /(K^-1) temperature 
        double Tincr;

    public:
        Process();

        //get the total steps and increment of a process from files
        void load_ctrl(Vector4d);

        //get the velocity gradient in a process file
        void get_Udot(Matrix3d);

        void get_Sdot(Matrix3d);

        //get the known and unknown flag tensor in a process file
        void get_IUdot(Matrix3i);
        void get_ISdot(Vector6i);

        //
        void loading(Polycs::polycrystal &);

};

}

#endif