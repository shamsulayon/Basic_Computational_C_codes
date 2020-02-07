years=0:10:150;
populations=[3.929 5.308 7.24 9.638 12.866 17.069 23.192 31.443 38.558 50.156 62.948 75.996 91.972 105.711 122.775 131.669];
p0 = [.01 1000 3.93];
optimset lsqcurvefit
lowerbound=[0 0 0];
options=optimset('TolFun',1e-8);
[p error]=lsqcurvefit(@logistic,p0,years,populations,lowerbound,[],options)
sqrt(error)
modelpops=logistic(p,years);
plot(years,populations,'o',years,modelpops)

%p = 0.0322  184.7937    3.7465
%error =11.3468
%ans =3.3685
