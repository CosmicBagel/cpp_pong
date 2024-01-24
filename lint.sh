#!/bin/bash

echo "clang-tidy..."
clang-tidy-17 src/*

echo -e "\ncppcheck..."
cppcheck src/*
