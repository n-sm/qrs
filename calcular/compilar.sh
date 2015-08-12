#!/bin/bash
gcc $(gnustep-config --objc-flags) $1 $(gnustep-config --base-libs)
