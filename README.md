# Frank-Wolfe-Method-tntp

Steps to Run:<br>
1) Download the zip file <br>
2) Exact <br>
3) In the commandline, cd to the fold <br>
5) type "make" into the commandline <br>
6) to run ./F_W.exe <br>
7) Chose either c for a custom set of a network and trips or chose d for the default set of the Chicago Regional<br>
<br>
NOTE:<br>
There are some data sets in the folder itself and others can be used either by:<br>
  -Placing the datasets in the folder (The preferred method)<br>
  -Using there paths as there location<br>
  (if nothing happens then there might be an issue opening up the datasets. Make sure everything is correctly inputted.)<br>
 <br>
 Where I got my datasets from: https://github.com/bstabler/TransportationNetworks.git
 <br>
 <br>
 Additionally it should be noted that some of the datasets in there default format<br>
 might not be formatted correctly. To do so, remove the ~comment lines but leave the ~header line. <br>
<br>
8) input the Miles cost which is a impedence cost of minute/mile. Each Dataset has a different Miles cost<br>
<br>
For the datasets in the folder already:<br>
(Chicago Regional) Mile Costs = 0.25<br>
(Chicago Sketch) Mile Costs = 0.04<br>
(Sioux Falls) Mile Costs = 0<br>
<br>
9) Lastly chose the number of integrations of the Frank-Wolfe method to do.<br>
<br>
Results) The results will be written out to a data.txt file. 
<br>
<br>
The impedence function used: t<sub>i</sub> = a<sub>i</sub> + a<sub>i</sub>(0.15)[(x<sub>i</sub>/capacity<sub>i</sub>)^4]<br>
Where:<br> 
       t<sub>i</sub> = the flow impedence time on link i<br>
       a<sub>i</sub> = free flow time for link i (given)<br>
       x<sub>i</sub> = flows on link i<br>
       capacity<sub>i</sub> = flow capacity for link i (given)<br>
       0.15 and 4 are just typical amounts used for this standard impedence function.<br>
<br>
The time function: time<sub>i</sub> = t<sub>i</sub> + mile<sub>costs</sub>(x<sub>i</sub>)<br>
Where: <br>
      time<sub>i</sub> = the total link time<br>
      mile<sub>costs</sub> = Mile Costs inputted<br>

Let me know if there are any issues<br>
<br>

