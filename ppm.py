import os
cwd = os.getcwd()
cwd = cwd+"/mypython/lib/python3.5/site-packages/"
f = open("packages.txt", "r")
packageList = f.read().splitlines()
f.close()
input_data=[]
for package in packageList:
	packageName,version = package.split("==") 
	input_data.append((packageName.strip().replace('-','_'),version.strip()))
#print(input_data)
#print(packageList)
for package in packageList:
	myCmd = "pip install {package} ".format(package=package)
	os.system(myCmd)
installedPackageList = os.listdir(cwd)
failedPackages = []
for package,version in input_data:
	packageName = package+"-"+version+".dist-info"
	if packageName not in installedPackageList:
		failedPackages.append(package+"=="+version)

if len(failedPackages):
	print("List of Failed Packages:")
	for package in failedPackages:
		print(package)
else:
	print("Successfully installed all the Packages")
#print(installedPackageList)
