#!/bin/bash

echo "clang-tidy..."
clang-tidy-17 --config-file=".clang-tidy" src/*

echo -e "\ncppcheck..."
cppcheck src/*
