#!/bin/bash
gcc $(gnustep-config --objc-flags) first.m $(gnustep-config --base-libs)
