# Welcome to Code Programming Language !

Code is an innovative programming language that combines the efficiency and speed of Go with the elegance and practicality of Python. It's designed to be fast, safe, and suitable for both systems programming and rapid application development.
```
module Geometry

export Circle, print_total_area

# Define a Circle type with a single field for the radius
struct Circle
    radius::Float32
    pi::Float32
end

# Define a module with a function to print the total area of a list of circles
module CircleHelpers
    export print_total_area

    # Function to calculate and print the total area of a list of circles
    function print_total_area(circles::Vector{Circle})
        total_area = 0.0f0
        for circle in circles
            total_area += 3.14 * circle.radius^2
        end
        println("Total area: ", total_area)
    end
end

end # module Geometry

# Main program
function main()
    # Create a list of Circle instances with different radii
    circles = [
        Circle(1.0f0),
        Circle(2.0f0)
    ]

    # Call the function to print the total area
    Geometry.CircleHelpers.print_total_area(circles)
end
```
## Killer Features of the Language

* Speed: Enjoy the performance of Mojo, making your applications run at lightning speed.
* Multiple Dispatch: Inspired by Julia, Code24 allows for sophisticated function behaviors based on argument types.
* Practicality: With a syntax as intuitive as Python's, Code24 is easy to learn and practical to use.
* Compilation: Supports both ahead-of-time and just-in-time compilation, similar to Dart, for flexibility in deployment.
* Null Safety: Borrowing from Swift, Code24 ensures null safety without the need for special syntax like "?" after data types.
* Expressions: Code24 adopts Kotlin and Rust's approach where most control-flow structures are expressions.
* Collections: Null-safe methods on collections are a feature, taking cues from Swift to prevent common errors.
* Memory Control: Offers close-to-the-metal memory and hardware control akin to Objective-C, with the safety of Go.
* Syntax: Code24 uses a Python and C/C++-based syntax that is familiar and easy to understand.
* Cross-Compiling: Seamlessly use C# and C/C++, R, Ruby, Fortran and many other's libraries within Code24, thanks to its cross-compiling capabilities.
* Interop: Enjoy smooth interoperation with C++ code and libraries.
* Visibility and Accessibility: Introduces hybrid visibility and accessibility modifiers for classes and subroutines.

## Built With

* Ada 2012 - Type System, Safety Features and Reliability
* Assembly - Embedded Systems, Systems Programming
* Machine Code - Manually adapting language for close-to-the-metal memory and hardware control.
* Objective-C/C++ - For memory and hardware allocation capabalities
* C/C++20 - The main programming language used
* LLVM (Version 18.1.5) - For constructing compiler
* CMake - A software construction tool
* Makefile - Compiling

## People behind the Code

* Tunjay Akbarli (Me) - Initial work - tunjayakbarli@it-gss.com
* Tural Guliyev - Lead Architect - turalquliyev@it-gss.com
* Teymur Novruzov - Lead Architect - teymurnovruzov@it-gss.com
* Mohammed Samy El-Melegy - Compiler Engineer - mohammedsamy@it-gss.com
* Uzo Ochogu - Compiler Engineer - uzoochogu@it-gss.com
* Martins Iwuogor - Compiler Developer - martinsiwuogor@it-gss.com
* Maryna Rybalko - Publisizing - maryna.rybalko@it-gss.com
* Ravan Sariyev - Publisizing - ravansariyev@it-gss.com

## Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are greatly appreciated.

If you have a suggestion that would make Code24 better, please fork the repo and create a pull request. You can also simply open an issue with the tag “enhancement”.

Don’t forget to give the project a star! Thanks again!

Feel free to customize this README to fit the specifics of your project and personal branding. Happy coding!
