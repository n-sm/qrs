#!/usr/bin/env php
<?php

$lineno = 1;
while(($line = fgets(STDIN)) != false)
{
    fputs(STDOUT, "$lineno $line");
    $lineno++;
}

?>