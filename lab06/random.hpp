// File: random.hpp
//   header file for simple random number generators


// return a uniformly distributed random number in the given range
double randu(double min, double max);

// return a uniformly distributed integer in the given range 
int randui(int min, int max);

// return a normally distributed number based on a distribution 
// with specified mean and sigma 
double randn(double mean, double sigma);

// return a number from the binomial distribution
//   inputs: int n
//           double b
//   Return: random sampling from Binomial(n,p)
int randbin(int n, double p);

