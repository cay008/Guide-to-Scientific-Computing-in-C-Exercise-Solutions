#include <iostream>
#include <cmath>
#include <fstream>
#include <cassert>

class AbstractOdeSolver
{
	private:
	double step_size;
	double initial_time;
	double final_time;
	double initial_value;
	double nof_nodes;
	
	public:
	
	//Default Constructor
	AbstractOdeSolver()
	{
		step_size = 0.01;
		initial_time = 0.0;
		final_time = 0.0;
		initial_value = 0.0;
	}
	
	void SetStepSize(double h)
	{
		step_size = h;
	}
	
	void SetTimeInterval(double t0, double t1)
	{
		initial_time = t0;
		final_time = t1;
	}
	
	void SetInitialValue(double y0)
	{
		initial_value = y0;
	}
	
	virtual double RightHandSide(double y, double t) = 0;
	virtual double* SolveEquation() = 0;
	
	//Access private members
	double GetStepSize()
	{
		return step_size;
	}
	double GetInitialTime()
	{
		return initial_time;
	}
	double GetFinalTime()
	{
		return final_time;
	}
	double GetInitialValue()
	{
		return initial_value;
	}

	public:
	void SetNofNodes(double t0, double t1, double h) //Set Number of Nodes 
	{
		nof_nodes = (int)(fabs(t1-t0) / h) + 1;
	}
	
	int GetNofNodes() //Return Number of Nodes
	{
		return nof_nodes;
	}
};

class ForwardEulerSolver : public AbstractOdeSolver
{
	private:
	double (*p_rhs_func)(double, double); //Pointer to RightHandSide Function, this is used in the method SolveEquation()
	
	public:
	void SetRightHandSidePointer(double (*p_myode_rhs)(double, double))
	{
		p_rhs_func = p_myode_rhs;
	}
	
	virtual double RightHandSide(double y, double t)
	{
		double rhs;
		rhs = (*p_rhs_func)(y, t);
		return rhs;
	}
	
	double* SolveEquation()
	{
		double* ode_solution = new double [GetNofNodes()];
		double previous_time = GetInitialTime();
		
		ode_solution[0] = GetInitialValue();
		for (int i = 1; i < GetNofNodes(); i++)
		{
			ode_solution[i] = ode_solution[i-1] + GetStepSize()*RightHandSide(ode_solution[i-1], previous_time);
			previous_time += GetStepSize();
		}
		
		return ode_solution;
	}	
};

 class RungeKuttaSolver : public AbstractOdeSolver
{
	private:
	double (*p_rhs_func)(double, double); //Pointer to RightHandSide Function, this is used in the method SolveEquation()
	
	public:
	void SetRightHandSidePointer(double (*p_myode_rhs)(double, double))
	{
		p_rhs_func = p_myode_rhs;
	}
	
	virtual double RightHandSide(double y, double t)
	{
		double rhs;
		rhs = (*p_rhs_func)(y, t);
		return rhs;
	}
	
	double* SolveEquation()
	{
		double k1 = 0.0, k2 = 0.0, k3 = 0.0, k4 = 0.0;
		double h = GetStepSize();
		double t_previous = GetInitialTime();
		double* ode_solution = new double [GetNofNodes()];

		ode_solution[0] = GetInitialValue();
		
		for (int i = 0; i < GetNofNodes(); i++)
		{
			k1 = h*RightHandSide(ode_solution[i], t_previous);
			k2 = h*RightHandSide(ode_solution[i] + 0.5*k1, t_previous + 0.5*h);
			k3 = h*RightHandSide(ode_solution[i] + 0.5*k2, t_previous + 0.5*h);
			k4 = h*RightHandSide(ode_solution[i] + k3, t_previous + h);
			ode_solution[i + 1] = ode_solution[i] + 1/6*(k1 + 2*k2 + 2*k3 + k4);
		}	

		return ode_solution;
	}	
}; 

//RHS of the ode to be solved
double rhs_of_myode(double y, double t)
{
	return 1 + t;
}

int main(int argc, char* argv[])
{
	//Solve ODE with forward euler
	ForwardEulerSolver odetest;
	
	double t0 = 0.0, t1 = 1.0, h = 0.001, y0 = 2.0;
	odetest.SetStepSize(h);
	odetest.SetTimeInterval(t0, t1);
	odetest.SetInitialValue(y0);
	odetest.SetRightHandSidePointer(rhs_of_myode);
	odetest.SetNofNodes(t0, t1, h);
	int nof_nodes = odetest.GetNofNodes();
	
	double* ode_solution_fe = new double [nof_nodes];
	ode_solution_fe = odetest.SolveEquation();

/* 	std::ofstream write_file_fe("ForwardEulerSolution.dat");
	write_file_fe.precision(16);
	assert(write_file_fe.is_open());
	double t_previous = t0;
	for (int i = 0; i < nof_nodes; i++)
	{
		write_file_fe << t_previous << " "<< ode_solution_fe[i] << "\n";
		t_previous += h;
	}
	write_file_fe.close(); */

	//Solve ODE with RK4
	RungeKuttaSolver odetest_rk4;

	odetest_rk4.SetStepSize(h);
	odetest_rk4.SetTimeInterval(t0, t1);
	odetest_rk4.SetInitialValue(y0);
	odetest_rk4.SetRightHandSidePointer(rhs_of_myode);
	odetest_rk4.SetNofNodes(t0, t1, h);
	
	double* ode_solution_rk4 = new double [nof_nodes];
	ode_solution_rk4 = odetest.SolveEquation();

/* 	std::ofstream write_file_rk4("RK4Solution.dat");
	write_file_rk4.precision(16);
	assert(write_file_rk4.is_open());
	t_previous = t0;
	for (int i = 0; i < nof_nodes; i++)
	{
		write_file_rk4 << t_previous << " "<< ode_solution_fe[i] << "\n";
		t_previous += h;
	}
	write_file_rk4.close(); */

	std::cout << ode_solution_rk4[nof_nodes-1] << "\n";

	delete[] ode_solution_fe;
	delete[] ode_solution_rk4;
	return 0;
}



