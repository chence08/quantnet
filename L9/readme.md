# Group A&B: Exact Pricing Methods

### Important Instructions

- Encapsulate all functionality into proper classes.
	- option pricing
	- greeks
	- matrix pricing
- **Submit Group A and Group B as a single, comprehensive project that takes all described functionality into account, and presents a unified, well-structured, robust, and flexible design.**
- Grading
	- Robustness
	- Flexibility
	- Clarity
	- Code commenting
	- Efficiency
	- Conciseness
	- Taking previously-learned concept into account
	- Correctness
- Your single `main()` function should fully test **each and every aspect of your option pricing classes**, to ensure correctness prior to submission.
- All answers to questions, as well as batch test outputs should be outlined in a document.
- Justifications for design decisions should be outlined in the document as well.

## A. Exact Solutions of One-Factor Plain Options

Exact formulae for plain (European) equity options (with zero dividends) and their sensitivities. These options can be exercised at the expiry time $T$ only.

### Objectives

- Given the exact solution for a given financial quantity (e.g., an option price), show how to map it to C++ code.
- Use STL and Boost libraries as often as you can.

The parameters whose values that need to be initialized are:

- $T$ (expiry time/maturity). This is a number, e.g. $T=1$ means one year. $K$ (strike price)
- sigma (volatility)
- $r$ (risk-free interest rate)
- $S$ (current stock price where we wish to price the option)
- $C=$ call option price, $P=$ put option price

Finally, we note that $n(x)$ is the normal pdf and $N(x)$ is the cdf, both of which are in Boost Random.

We give the set of test values for option pricing.

| Batch | sig  | K    | T    | r    | S    | C        | P       |
| ----- | ---- | ---- | ---- | ---- | ---- | -------- | ------- |
| 1     | 0.3  | 65   | 0.25 | 0.08 | 60   | 2.13337  | 5.84628 |
| 2     | 0.2  | 100  | 1    | 0    | 100  | 7.96557  | 7.96557 |
| 3     | 0.5  | 10   | 1    | 0.12 | 5    | 0.204058 | 4.07326 |
| 4     | 0.3  | 100  | 30   | 0.08 | 100  | 92.17570 | 1.24750 |

### Black-Scholes formula

The formulae apply to option pricing on a range of underlying securities, but we focus on stocks in these exercises.

#### Call Option

The cost-of-carry parameter $b$ has specific values depending on the kind of security in question:

- $b=r$ is the Black-Scholes stock option model
- $b=r-q$ is the Morton model with continuous dividend yield $q$.
- $b=0$ is the Black-Scholes futures option model
- $b=r-R$ is the Garman and Kohlhagen currency option model, where $R$ is the foreign risk-free interest rate.

#### Put option

#### Put-call parity

This formula is used when creating trading strategies.

## Questions

1. Implement the above formulae for call and put option pricing using the data sets Batch 1 to 4.

2. Apply the put-call parity relationship to compute call and put option prices. For example, given the call price, compute the put price using Batches 1 to 4. Check your answers with the prices from part 1.

	1. Mechanism to calculate the call (or put) price for a corresponding put (or call) price OR
	2. Mechanism to check if a given set of put/call prices satisfy parity.

	The ideal submission will neatly **implement both approaches**

3. Say we wish to compute option prices for a monotonically increasing range of underlying values of $S$, for example $10,11,12,\dots,50$. To this end, the output will be a vector. This entails calling the option pricing formulae for each value $S$ and each computed option price will be stored in a `std::vector<double>` object.

	> It will be useful to write a global function that produces a mesh array of doubles separated by a mesh size $h$.

4. Now we wish to extend part 3 and compute option prices as a function of:

	- expiry time
	- volatility
	- any of the option pricing parameters

	Essentially, the purpose here is the be able to input a matrix (vector of vectors) of option parameters and receive a matrix of option prices as the result.

	Encapsulate this functionality in the most flexible/robust way you can think of.

### Option Sensitivities (Greeks)

1. Implement the above formulae for gamma for call and put **future option** pricing using the data set

| S    | K    | T    | r    | sig  | b    | call   | put     |
| ---- | ---- | ---- | ---- | ---- | ---- | ------ | ------- |
| 105  | 100  | 0.5  | 0.1  | 0.36 | 0    | 0.5946 | -0.3566 |

2. We now use the code in part 1 to compute call delta price for a monotonically increasing range of underlying values of $S$, for example $10,11,12,\dots,50$. To this end, the output will be a `vector` and it entails calling the above formula for a call delta for each value $S$ and each computed option price will be stored in a `vector<double>` object. It will be useful to reuse the above global function that produces a mesh array of double separated by a mesh size $h$.

3. Incorporate this into your above **matrix pricer** code, so you can input a matrix of option parameters and receive a matrix of either Delta or Gamma as the result.

4. We now use divided differences to approximate option sensitivities. In some cases, an exact formula may not exist (or is difficult to find) and we resort to numerical methods. In general, we can approximate first and second-order derivatives in $S$ by 3-point second order approximations, for example:
$$
  \begin{align}
  \Delta&=\frac{V(S+h)-V(S-h)}{2h}\\
  \Gamma&=\frac{V(S+h)-2V(S)+V(S-h)}{h^2}
  \end{align}
$$
  In this case the parameter $h$ is 'small' in some sense. By **Taylor's expansion** you can show that the above approximations are second order accurate in $h$ to the corresponding derivatives.

  > The objective of this part is to perform the same calculations as in part 1 and 2, but now using divided differences. Compare the accuracy with various values of the parameter $h$ (In general, smaller values of $h$ produce better approximations but we need to avoid **round-offer errors** and subtraction of quantities that are very close to each other). Incorporate this into your well-designed class structure.

## B. Perpetual American Options

An European option can only be exercised at the expiry date $T$ and an exact solution is known. An American option is a contract that can be exercised at any time prior to $T$. Most traded stock options are American style. In general, there is no known exact solution to price an American option but there is one exception, namely perpetual American options. The formulae are:

### Call

### Put

In general, the perpetual price is the time-homogeneous price and is the same as the normal price when the expiry price $T$ tends to infinity. In general, American options are worth more than European options.

### Questions

1. Program the above formulae, and incorporate into your well-designed options pricing classes.

2. Test the data with

	| S    | K    | sig  | r    | b    | C       | P       |
	| ---- | ---- | ---- | ---- | ---- | ------- | ------- |
	| 110  | 100  | 0.1  | 0.1  | 0.02 | 18.5035 | 3.03106 |

3. We now use the code in part 1 to compute call and put option price for a monotonically increasing range of underlying values of $S$, for example $10,11,12,\dots,50$. To this end, the output will be a vector and this exercise entails calling the option pricing formulae in part 1 for each value $S$ and each computed option price will be stored in a vector object.

	> It will be useful to reuse the above global function that produces a mesh array of double separated by a mesh size $h$.

4. Incorporate this into your above **matrix pricer** code, so you can input a matrix of option parameters and receive a matrix of Perpetual American option prices.

# Groups C&D: Monte Carlo Pricing Methods

## C. Monte Carlo 101

For this section, all necessary code is provided.

**You are expected so submit a document with the answers to the below three questions, but not any code.**

The document should contain a detailed, complete analysis and will be graded on how well it demonstrates understanding of the accuracy and efficiency of Monte Carlo methods in the below context.

We focus on a linear, constant-coefficient, scalar (one-factor) problem. In particular, we examine the case of a **one-factor European call option** using the assumptions of the original Black-Scholes equation. We given an overview of the process.

At the expiry date $t=T$, the option price is known as a **function of the current stock price and the strike price**. The essence of the Monte Carlo method is that we carry out simulations experiment by finding the solution of a SDE from time $t=0$ to time $t=T$. This process allows us to compute the **stock price** at time $t=T$ and then the **option price** using the payoff function. We carry out $M$ simulations or draws by finding the solution of the SDE and we calculate the option price at $t=T$. Finally, we calculate the discounted average of the simulated payoff and we are done.

### Questions

1. Study the source code in the file *TestMC.cpp* and relate it to the theory that we have just discussed.
2. Run the MC program again with data from Batches 1 and 2. Experiment with different value of `NT` (time steps) and `NSIM` (simulations or draws). In particular, how many time steps and draws do you need in order to get the same accuracy as the exact solution? How is the accuracy affected by different values for `NT`/`NSIM`?
3. Now we do some stress testing of the MC method. Take Batch 4. What values do we need to assign to `NT` and `NSIM` in order to get an accuracy to two places behind the decimal point? How is the accuracy affected by different values for `NT`/`NSIM`?

## D. Advanced Monte Carlo

This section will build upon the provided Monte Carlo code from the previous, by adding methods to track the accuracy of the MC simulation.

**You are expected to submit code in addition to a document with the answers to the below questions.**

We wish to add functionality to the Monte Carlo pricer by providing estimates for the standard deviation (SD) and standard error (SE), defined by:

Implement this new functionality and test the software for a range of data for call and put options.

### Questions

1. Create generic functions to compute the SD and SE based on the above formulae. The inputs are a vector of size $M=$`NSIM`, the interest-free rate and expiry time $T$. Integrate this new code into TestMC.cpp Make sure that the code compiles.
2. Run the MC program again with data from Batches 1 and 2. Experiment with different values of `NT` and `NSIM`. How do SD and SE react for these different run parameters, and is there any pattern in regards to the accuracy of the MC (when compared to the exact method)?

# E. Excel Visualization

You will need to tweak the code (i.e. the Excel Import paths) to work on your own machine and MS Excel version.

**Submission should consist of the working code and example Excel output files.**

### Questions

1. Compile and run the sample programs TestSingleCurve.cpp, TestTwoCurve.cpp and TestMultipleCurve.cpp. Make sure that everything compiles and that you get Excel output.

2. We now wish to compute option price for a monotonically increasing range of underlying values of $S$, for example $10,11,12,\dots,50$​. To this end, the output will be a vector and this exercise entails calling the option pricing formulae in part 1 for each value $S$ and each computed option price will be stored in a vector object.

	> It will be useful to reuse the above global function that produces a mesh array of double separated by a mesh size $h$.

	Print the output in Excel.

# F. Finite Difference Methods (Introduction)

**Submission should consist of the working code, example Excel output files, and a document analyzing the accuracy of FDM versus the exact method.**

### Questions

1. Compile and run the project as in and make sure that you get Excel output. Examine the code and try to get an idea of what is going on.
2. In this exercise we test the FD scheme. We run the programs using the data from Batches 1 to 4. Compare your answers with those from the previous exercises.