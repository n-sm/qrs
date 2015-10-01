create table tabej1
(      
col1 char(4),
col2 int,
col3 int,
col4 int,
col5 int,
col6 int	
);

load data infile '/tmp/tabej.csv' into table tabej1
     columns terminated by ' '
     ignore 1 lines;
