#!/bin/bash
find . -type f -name "*.sh" | sed 's/.*\///' | sed 's/\.sh$//'
