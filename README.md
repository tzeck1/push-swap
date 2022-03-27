# push_swap
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

<img width="198" alt="Screenshot 2022-03-27 at 20 18 28" src="https://user-images.githubusercontent.com/65648486/160295090-be0907c7-e884-4464-bc16-b37e7ec22f73.png">


![ezgif-1-c4f3170bb7](https://user-images.githubusercontent.com/65648486/160295375-4e9d9aad-029d-4e14-964a-5e8c6305aff1.gif)


## Usage

``make`` to compile source files

``./push_swap <insert numbers>`` for sorting <br>
``ARG="<numbers>"; ./push_swap $ARG | checker_mac $ARG`` to verify the result <br>
``python3 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"` ``  to visualize the sorting
