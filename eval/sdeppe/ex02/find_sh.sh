find . -name "*.sh"  -printf "%f\n" | sed "s/\.sh//" |  sed "s/^\.//"
