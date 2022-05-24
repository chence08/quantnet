# 4.1 Template (Generic) Programming

**OOP**

- Classes and inheritance

- **Subtype polymorphism** (virtual functions in base class)

	```c++
	class Shape
	{
	public:
	    virtual void draw() const = 0;
	};
	class Line : public Shape
	{
	public:
	    void draw() const { cout << "Line" << endl; }
	};
	class Circle : public Shape
	{
	public:
	    void draw() const { cout << "Circle" << endl; }
	};
	```

	```c++
	void draw(const list<Shape*>& v)
	{
	    list<Shape*>::const_iterator it;
	    
	    for (it = v.begin(); it != v.end(); ++it)
	    {
	        (*it)->draw();
	    }
	}
	```

	- Traditional OO code
	- Run-time behaviour (vtabl)
	- Not highly reusable code

- There are the interface requirements

**GP**

- Seperates data structure and algorithms

- Use abstract requirements specification

- We can use **parametric polymorphism**

  ```c++
  class Valve
  {
  public:
      virtual void draw() const = 0;
  };
  class BallValve : public Valve
  {
  public:
      void draw() const { cout << "Ball valve" << endl; }
  };
  class CheckValve : public Valve
  {
  public:
      void draw() const { cout << "Check valve" << endl; }
  };
  ```

  ```c++
  template <class DrawableThing> void draw(const vector<DrawableThing>& v)
  {
      vector<DrawableThing>::const_iterator it;
      for (it = v.begin(); it != v.end(); ++it)
      {
          (*it)->draw(); // Make assumption on the type(pointer) of DrawableThing
      }
  }
  ```

  - Operates with any class that implements a draw function
  - Simple example of a policy
  - Compile-time behaviour
  - Code is reusable, and it depends on standardised interface

- ## Usage, Hierarchy I

    ```c++
    cout << "\nNow printing Valves\n";
    BallValve bv1;
    CheckValve cv1;
    
    vector<Valve*> network(2);
    network[0] = &bv1;
    network[1] = &cv1;
    
    draw(network);
    ```

- ## Usage, Hierarchy II

    ```c++
    Line lin;
    Circle cir;
    
    cout << "\nNow printing shapes\n";
    vector<Valve*> figure(2);
    figure[0] = &lin;
    figure[1] = &cir;
    
    draw(figure);
    ```

- Similar to Abstract Data Type (ADT) behaviour
- Focus is on efficiency and compile-time behaviour

## Traditional Usage

```c++
Line lin;
Circle cir;

// Now the traditional OO approach
list<Shape*> figure2;
figure2.push_back(&lin);
figure2.push_back(&cir);

draw(figure2);
```

## Comparing OOP and GP

- Virtual functions are slower than function templates
- Run-time dispatching or compile-time dispatching?
- Risk of code bload with template based programs
- Reusability: too much inheritance limits it

------

- Need to switch mindset from traditional OOP
- Instead of inheritance hierarchies, think of contracts between ADTs
- Document using UML components diagrams

## OOP or GP?

- Can simulate inheritance with generics
- Can simulate genericity with inheritance (common in GOF (Gang of Four) patterns)

```c++
template <typename N>
N Max(const N& x, const N& y)
{ // N is a generic type
    if (x > y) return x;
    return y;
}
```

## Using Template Function

```c++
Max<int>(d1, d2);
```

GP is necessary for the future.

# 4.2 Introduction to Templates

Templates are descriptors for classes

Typical classes include

- bags
- sets
- list trees
- arrays
- maps
- stacks
- sorted_arrays
- matrices
- queues
- symbol_tables

## Including Source Files

- Template source file is included
- To prevent multiple inclusion create `#ifndef` structure
- Sometimes tempate is not separated in different files, template is placed in single file with extension ".tpp" or just ".h"

## Practicalities

- When creating template classes, you choose between inline code (1 file) or separate header or source file

# 4.3 Overview of the Standard Template Library (STL)

## What is STL?

- ANSI standard library for commonly occuring C++ classes
- Makes extensive use of the C++ template mechanism
- Lean and mean (no frills attached)

## STL Components

1. Containers (collections): Placeholders for related groups of objects of a given type
	1. All containers organise a collection of objects of the same type
	2. Sequence containers follow a strictly linear regime
	3. Sorted associative containers allow fast retrieval of objects based on keys
2. Algorithms: Generic operations to be performed on containers
	1. Can group algorithms based on their semantics
	2. Nonmutating sequence do not change contents of container (read-only)
	3. Mutating sequence modify container on which they operate (write-enabled)
	4. Sorting-related (sort, merge, searching) applicable to sorted sequences
	5. Generalised numeric algorithms (a small collection of simple maths stuff)
3. Iterators: Intermediaries between containers and algorithms
	1. Pointer-like objects
	2. Algorithms use them to traverse containers
	3. Concept of **iterator range** is important (e.g. `[first, end)`)
	4. Iterator categories
		1. Input iterator: read one element at a time (in forward direction only)
		2. Output iterator: writes one element at a time (in forward direction only)
		3. Forward iterator: combines functionality of input and output iterators
		4. Bi-directional: A forward iterator that can also move backwards
		5. Random access iterator: A 'jumpy' bi-directional iterator
	5. Using iterators
		1. Iterator type nested in container class
		2. Use operator `!=` to compare iterators (operator `<` is not supported)
		3. Dereference iterator to get the current value
4. Function objects: Similar to Command design pattern (Gamma)
	1. This is an object that encapsulates a function
	2. Create such an object by overloading the function call operator `operator ()`
	3. Useful (saves code duplication and makes code more reusable)
5. Adaptors: Change the **interface** of containers, algorithms and iterators
	1. Possible to create new classes with restricted interfaces (e.g. stack)
	2. Useful for customisation purposes
6. Allocators: For controlling storage management
	1. Encapsulate information about memory models
	2. There exists a Default Allocator Interface
	3. Types: reference, const_reference, pointer and const_pointer
	4. Default allocator uses standard `new` and `delete`
	5. Can create custom allocators that for example allocates memory in a fixed memory pool (faster but less memory efficient)

### Main Container Types

- First class
	- Sequence
		- list
		- vector
		- deque
	- Associative
		- set
		- multiset
		- map
		- multimap
- Adapter
	- stack
	- queue
	- priority_queue

## Some Examples

1. Vector and vector iterator

	1. Array of `T`
	
	2. Provides random-access to elements
	
	3. Only possible to add elements at the back
	
   4. Vector offers random-access iterator
   
   5. Include `<vector>` header file

   6. Vector
        ```c++
	     #include <vector>
        using namespace std;
        
        // Declare vector 2 elements.
        vector<double> v(2);
	     
        // Write access to elements.
        v[0] = 1;
        v[1] = 2;
	     v.push_back(3); // Increase size of vector!
	     
	     // Read access to elements.
	     cout << v[0] << v[1] << v[2] << endl;
	     ```
	     
	6. Vector Iterator
	   
	     ```c++
	     // Get (random access) iterator.
	     vector<double>::iterator iter = v.begin();
	     
	     // Use iterator for random access.
	     cout << iter[0] << iter[1] << iter[2] << endl;
	     
	     // Use iterator for traversal.
	     const vector<double>::iterator end = v.end();
	     for (iter = v.begin(); iter != end; iter++)
	     {
	         cout << *iter << endl; // Dereference iterator
	     }
	     ```
	
1. List and List Iterator

	1. Doubly linked list of `T`
	
	2. Possible to add and remove elements at the front, in the middle and at the back of the list.
	
	3. **No random access**, iterator jumps from one element to the next
	
   4. Include `<list>` header file
   
   5. ```c++
	    #include <list>
       using namespace std;
   
	  list<int> l;
   
     // Add data
     l.push_back(2);
     l.push_back(3);
	  l.push_front(1);
   
     // Use iterator for traversal
     list<int>::iterator iter;
	  const list<int>::iterator end = l.end();
	  for (iter = l.begin(); iter != end; iter++)
	  {
	      cout << *iter << endl;
	  }
	
	  ```

# 4.4 Sequence Containers

- Container whose elements are arranged in strict linear order
- Can write code that is independent of particular internal details
- This approach improves software maintainability and flexibility
- vector, deque, list
- Sequence containers do not do any ordering

**Remarks**

- STL embodies family of abstractions idea: sequences have similar interfaces
- STL Containers are template classes
- Choose best sequence based on performance criteria

## General Interface

- All sequence containers have same kind of interface
	- Constructors for creating a filled container
	- Different insertion functions
	- Different erase functions
- Sequence containers have two refinements
	- Front insertion sequence (constant time): only doubly linked list, deque
		- Get an element from the front
			- `front()`
			- precondition: `!empty()`
		- Push an element at the front
			- `push_front()`
		- Remove an element from the front
			- `pop_front()`
			- precondition: `!empty()`
	- Back insertion sequence (constant time): vector, list, deque
		- `back()`
		- `push_back()`
		- `pop_back()`

## Container Types

Each container defines its own

- Element type
- Pointer to element
- Reference to element
- Iterators to traverse container

### Vector (Stack)

- Fast random access to a sequence of dynamically varying length
- Fast insertions/deletions at **end of sequence**
- One should choose a deque over a vector if he wants to either add or delete from both ends like a Queue.
- Random access iterators provided
- A vector has two internal sizes
	- number of elements
	- capacity

#### Main Member Functions

- Constructor
	- default, copy and with a given size
- Accessors
	- `begin()`, `end()`, `rbegin()`, `rend()`
	- `r` means reverse iterator, move towards the beginning of the map
- Insertion
	- `push_back()`, `insert()`
- Deletion
	- `pop_back()`, `erase()`
- Sizes
	- `size()`, `max_size()`, `capacity()`
- Elements
	- `operator[]`
- Ability to reserve storage for future extensions
	- `reserve (size_type n)`

### List

- Is a doubly linked list
- Supports forward and backward traversal
- No random iterators
	- Some key generic algorithms cannot be used
- Insertion never invalidates iterators
- Deletion only invalidates the element being deleted
- Splicing possible
	- Transferring elements from one sequence to another

#### Main Member Functions in List

- Constructor
	- default, copy and with a given size
- Accessors
	- `begin()`, `end()`, `rbegin()`, `rend()`
	- `r` means reverse iterator, move towards the beginning of the map
- Insertion
	- `push_front()`, `push_back()`, `insert()`
- Deletion
	- `pop_front()`, `pop_back()`, `erase()`

#### Other Specials Functions in List

| functions | effect                                            |
| --------- | ------------------------------------------------- |
| splice()  | copies part into another list                     |
| unique()  | makes element unique                              |
| remove()  | remove all elements with a given value            |
| merge()   | merging of two lists                              |
| sort()    | sort a list based on a comparison function object |
| swap()    | swap contents of two lists                        |

### Deque (double ended queue)

- Similar to vector in terms of functionality
- Main difference is performance
- Insertion/deletion at start of deque take constant time
- Provide random access iterators
- Insertions/deletions in the middle take linear time

#### Main Member Functions in Deque

- Same as for vector
- Does not have `capacity()` and `reserve()`
- Additional functions: `push_front()`, `pop_front()`

# 4.5 Iterators in STL

- An entity that is used to traverse the elements of a collection
- Collections may be STL containers, regular C arrays, C++ iostream
- Positioned at exactly one place in a collection at any point in time
- Remains positioned there until instructed to move
- In fact, a pointer-type object acts as interface between algorithms and data structures

## Iterator Value Types

- Dereferenceable
	- Iterator points to element in the data structure
- Past the end
	- Iterator points after the last element in the data structure
- Singular
	- Points to nothing (like `NULL` pointer)

## Obtaining an Iterator

- For arrays: a pointer in an array is an iterator
- STL containers provide functions that return iterators: `begin()`, `end()`

## Iterator Categories

- Trivial iterator

	- May be dereferenced to refer to some type

	- Simple iterator that does not iterate

	- Refinement of Assignable, Default Contructible and Equality Comparable

	- It can be dereferenced

	- Trivial iterator can be

		- Mutable
		- Constant

	- Trivial Iterator example: Pointer to a variable

	- ```c
		X x; // Default constructor
		*x // Deference
		*x=t; // Dereference assignment (only for mutable iterator)
		x->m; // Member access
		```

- Input

	- Read one item at a time, forward direction

	- Read only iterator

	- Refinement of Trivial iterator

	- Iterates in forward direction only

	- No guarantee for possibility to pass through the same range twice

	- Example: class `istream_iterator`

	- ```c
		*i; // Return a read-only reference to element at i's current position
		i == j; // True if both i and j are both positioned at same element
		i != j; // Negation of i == j
		```

- Output

	- Write one item at a time, forward direction

	- Writes values into a sequence

	- No possibility to read

	- Is refinement of Assignable and Default Constructible

	- Iterates in forward direction only

	- Different subtypes

	- No guarantee for possibility to pass through the same range twice

	- ```c
		*i; // Returns a writeable reference to elements at i's current position
		i = j; // Set i's position to the same as j's
		// Note a == operator may not be available
		```

- Forward
	- Combination of input + output
	- Both an input iterator and output iterator
	- Reading and writing in one direction
	- Possible to save a forward iterator and use to start traversing from same position
	- Useful for multipass algorithms as opposed to single pass algorithms
- Bi-directional
	- Forward + ability to travel backwards
	- Example: `list<TYPE>::iterator`
- Random access
	- Bi-directional + ability to jump by an arbitrary distance
	- Example: `vector<TYPE>::iterator`

# 4.6 Algorithms in STL

## Header Files

- `<algorithm>` - the STL algorithms
- `<numeric>`
- `<functional>` - for function objects and function adapters
- And auxiliary functions, e.g. `max(), min(), swap()`

## Non-modifying Algorithms

- Change neither order nor values of elements in containers
- Used with input (read access) and forward iterators
- Can be used for all standard containers
- Another sub category: **non-modifying algorithms for sorted input ranges**

### Examples

- `for_each()`: perform an operation on each element (read-only)

## Modifying Algorithms

- Changes the value of elements
- Can also change the elements of a range while being copied into another range
- Major ones: `for_each()` (read-write) and `transform()`

### Examples

- Copy ranges
- Merge ranges
- Replace elements in ranges
- Replace elements with the result of an operation

## Removing Algorithms

- Special kind of modifying algorithms
- Remove elements in a range or while copying into another range
- Cannot use associative containers as destination (elements are constant)
- !! Remove logically and remove physically (`remove()` vs `erase()`)

### Examples

- Remove elements with given value or match a criterion
- Remove adjacent duplicates
- Copy elements while removing adjacent duplicates
- Copy elements that do not match a given criterion

## Mutating Algorithms

- Change order of elements (not values)
- Assign and swap values
- Cannot use associative as destination (elements are non constant)

### Examples

- Reverse
- Rotate
- Permutations
- Shuffling

## Sorting : Mutating

- Worse than linear complexity
- These algorithms require random access iterators

### Examples

- Sort all elements
- Sort and preserve order of equal elements (stable sort)
- Partial sort
- Convert a range to a heap
- Sort a heap

### Sorted Range Algorithms

## Numeric Algorithms

- Good use of operator overloading possibilities

### Examples

- Combine all element values (sum, products)
- Inner products (operator overloading)
- Partial sums
- Adjacent different (combine elements with their predecessor)

## Function Objects

## String Algorithms

## Copy Algorithm

## Find Algorithm

# 4.7 Associative Containers (extra)

- Variable sized container
- Elements are ordered
- Does not provide insertions at certain position because of sorting of elements
- Each element has a value and a key
- Elements looked-up by their keys
- Not all containers provide assignable values
- Does not provide mutable iterators
- Use binary search or hashing
- Sorted associative containers are:
	- set
	- multiset
	- map
	- multimap

## Associative Container Types

1. Unique associative container
	- set, map, (hash_set), (hash_map)
2. Multiple associative container
3. Simple associative container
	- set, multiset
4. Pair associative container
5. Sorted associative container
6. (Hashed associative container)

# 6.1-6.2 Applications Computational Finance

## C++ Top 10 Skills

1. How data is created, allocated, used and destroyed
2. Different kinds of functions: global, members, function pointers, function objects
3. How data and functions combine; namespaces, structs, classes
4. Pointers and their uses
5. The `const` stuff
6. Creating basic robust classes
7. STL; vector, iterators, algorithms; a bit of Boost is also useful
8. Design: inheritance, composition
9. Single Responsibility Principle (SRP)
10. Partition QF applications into loosely coupled subsystems

## Problem Dimensions

1. Range of applications in computational finance
	- Main interest is (1-factor) option pricing (equity, fixed income)
	- PDE, Monte Carlo, lattice, exact models
	- Related applications; calibration, interpolation, numerical algorithms
	- Each model has its advantages and disadvantages (efficiency, applicability, learning curve)
2. Numerical algorithms
3. Software design and implementation
4. Using C++ libraries
5. C++ and its use in applications
6. Debugging and testing

## Main Problems

- PDE methods (FDM, FEM, meshless, spectral)
	- Option model described as a PDE defined in some region of $(S, t)$ space
	- Can be one-factor or multi-factor equations
	- Describle any **contingent claim** that 'depends' on some **underlying variable**
	- Most PDEs are of **convection-diffusion** type
	- Approximate PDE by FDM
	- Solve discrete assembled equations by matrix solvers
	- We discretise in space and time (different methods)
	- Stability and accuracy of finite difference schemes
	- **Main FDM Categories**
		- Alternating Direction Implicit (ADI)
		- Method of Fractional Steps ("Soviet Splitting")
		- Alternating Direction Explicit (ADE)
		- Others, sub-themes and variations
	- **Stochastic Differential Equations (SDE)**
		- Describe random behaviour of underlying variables (one-factor, $n$-factor)
		- No closed solution in general
		- Use FDM to approximate SDE
		- Use SDE as basis for Monte Carlo and lattice methods
- Integral methods (Conv, Cos, Fourier)
- Simulation methods (Monte Carlo, Lattice(binomial, trinomial))
	- **Monte Carlo**
		- A simulation method; based in multiple times doing a 'SDE-FDM' trajectory
		- Geometric Brownian Motion (GBM); random walk on $[0, T]$
		- Take multiple samples
		- Discount summed values from $t=T$ to $t=0$
	- **Lattice Methods**
		- Similar to Monte Carlo in spirit and structure
		- We trace the evolution of the underlying in time (it can go up or down) up to $t=T$ (forward induction)
		- We then carry out **backward induction** from $t=T$ to $t=0$
		- The price at $t=0$ is the option price
- Exact/closed solutions

## Some Use Cases

- Price options (equity, fixed income, interest rate, hybrid)
- Hedging and option sensitivities
- Calibration and parameter estimation

## How do we evaluate a Method?

- Applicability to a wide range of derivatives types
- Robustness (works for all parameters), accuracy and efficiency
- Ease of use/implementation
- Maintainability (becomes important when software system starts to stabilise)

### FDM

- Accuracy and efficiency are advantages
- Difficulty in setting up the schemes and fine-tuning
- FDM for $n$-factor problems difficult for $n\geq 4$.

### Monte Carlo

- Applicable to a wide range of option types
- Easy to apply (a blunt instrument)
- Difficulty with computation of option sensitivities and early exercise
- Slow convergence, not very accurate method
- Mathematical foundations not as strong as with PDE methods

### Exact Solutions

- It might take forever to come up with a solution

## FDM Building Blocks

- Creating meshes in $S$ and $t$
- Vectors and matrices
- Data structures for PDE and FDM entities
- Payoff functions

## MC Building Blocks

- Random number generators
- Data structures for SDE and FDM
- Vectors and matrices
- Payoff functions

## Lattice Building Blocks

- Lattice data structures
- Algorithms to compute jumps
- Payoff entities

# 6.3 Option Pricing Exact Solutions

Topics

1. Plain option pricing, one factor
2. American perpetual options
3. Affine models (CIR (*Cox-Ingersoll-Ross model*), Vasicek)

## European Options

- One factor calls and puts
- Exact formulae for price (and sensitivities (greeks)) known
- These formulae expressed in terms of the normal cumulative distribution function

### Call Option

- $C$ is my call price
- $S$ is my underlying stock
- $b$ is cost of carry
- $r$ is risk-free interest rate
- $T$ is expiry time
- $N$ is cumulative normal distribution function
- $K$ is strike price

$$
\begin{align}
C&=Se^{(b-r)T}N(d_1)-Ke^{-rT}N(d_2)\\
N(x)&=\frac{1}{\sqrt{2\pi}}\int_{-\infty}^xe^{-y^2/2}dy\\
d_1&=\frac{\ln(S/K)+(b+\sigma^2/2)T}{\sigma\sqrt{T}}\\
d_2&=\frac{\ln(S/K)+(b-\sigma^2/2)T}{\sigma\sqrt{T}}=d_1-\sigma\sqrt{T}
\end{align}
$$

### Call Sensitivities

> Derivatives of the option price with respect to the underlying stock

$$
\begin{align}
\Delta_C&\equiv\frac{\partial C}{\partial S}=e^{(b-r)T}N(d_1)\\
\Gamma_C&\equiv\frac{\partial^2 C}{\partial S^2}=\frac{\partial\Delta_C}{\partial S}=\frac{Kn(d_1)e^{(b-r)T}}{S\sigma\sqrt{T}}
\end{align}
$$

### Remarks

- Use the formulae to price options on stocks ($\pm$ dividends), indexes, futures and currencies
- We can use it for different purposes (e.g. determining the accuracy of numerical methods)
- The formula can be extend to $n$-factor problems (but an explicit formula may not be forthcoming!)
- There are assumptions underlying the Black-Scholes model

## Early Exercise Features

- American options can be exercised at any time up to the expiry date
- No exact solution known, although 'exact approximations' exist (Barone-Adesi-Whaley)
- In general we need to employ numerical methods
- For the infinite time to expiration case we do have an exact formula (American perptual option)

### Remarks

- In general, the solution $V(S)$ is independent of time (depends only on the level of the underlying $S$)
- The option value can never go below the early exercise payoff $V\geq\max(K-S,0)$ (for a put option)
- Behaviour is describled by the solution of an ordinary differential equation
- Can be solved exactly (and of course, numerically)
- Can use the price to test other schemes when the expiry time approaches infinity

### Perpetual Call

### Perpetual Put

## Affine Interest Rate Models

- We also wish to model interest rate derivatives
- Many models used (Vasicek, CIR, Hull-White, ...)
- Fundamental to this is to model the short rate and term structure of interest rates
- This usually takes the form of a SDE

### SDE Model

### Affine Models

- Provide bond price based on given SDE
- The parameters $A(t)$ and $B(t)$ will be different for each model
- Most models are mean-reverting

# 6.4 Monte Carlo Simulation



# 6.5 Finite Difference Methods

# 6.6 Lattice Methods

- To show the applicability of the one-factor and two-factor binomial options pricing model
- Have an option calculator
- Create lattice data structures

