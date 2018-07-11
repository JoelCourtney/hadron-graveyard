prefix SIPrefixes:
	[Y_] = 1e24[_]
	[Z_] = 1e18[_]
	[E_] = 1e18[_]
	[P_] = 1e15[_]
	[T_] = 1e12[_]
	[G_] = 1e9[_]
	[M_] = 1e6[_]
	[k_] = 1e3[_]
	[h_] = 1e2[_]
	[da_] = 1e1[_]
	[d_] = 1e-1[_]
	[c_] = 1e-2[_]
	[m_] = 1e-3[_]
	[\mu_] = 1e-6[_]
	[n_] = 1e-9[_]
	[p_] = 1e-12[_]
	[f_] = 1e-15[_]
	[a_] = 1e-18[_]
	[z_] = 1e-21[_]
	[y_] = 1e-24[_]

prefix BinaryPrefixes:
	[Ki_] = 1024[_]
	[Mi_] = 1024[Ki_]
	[Gi_] = 1024[Mi_]
	[Ti_] = 1024[Gi_]
	[Pi_] = 1024[Ti_]
	[Ei_] = 1024[Pi_]
	[Zi_] = 1024[Ei_]
	[Yi_] = 1024[Zi_]

quantity [[Length]]
quantity [[Mass]]
quantity [[Time]]
quantity [[Charge]]
quantity [[Temperature]]
dimensionless quantity [[AmountOfSubstance]]
dimensionless quantity [[Angle]]

compound quantity [[Speed]] = [[Length / Time]]
compound quantity [[Acceleration]] = [[Velocity / Time]]
compound quantity [[Jerk]] = [[Acceleration / Time]]
compound quantity [[Force]] = [[Mass * Acceleration]]
compound quantity [[Torque]] = [[Force * Length]]
compound quantity [[Momentum]] = [[Mass * Velocity]]
compound quantity [[AngularMomentum]] = [[Mass * Velocity * Length]]
compound quantity [[Energy]] = [[Force * Length]]
compound quantity [[Power]] = [[Energy / Time]]
compound quantity [[Current]] = [[Charge / Time]]
compound quantity [[EMF]] = [[Energy / Charge]]
compound quantity [[Resistance]] = [[EMF / Current]]
compound quantity [[Conductivity]] = 1/[[Resistance]]

unit family SILength quantifies [[Length]]:
	[m]
	prefix [m] SIPrefixes

	base [m]
	avoid ([hm],[dam],[dm])

unit family ImperialLength quantifies [[Length]]:
	# Standard Imperial Length
	[thou]
	[in] = 1000[thou]
	[ft] = 12[in]
	[yd] = 3[ft]
	[ch] = 22[yd]
	[fur] = 10[ch]
	[mi] = 8[fur]
	[lea] = 3[mi]

	base [ft]
	avoid ([thou],[ch],[for],[lea])
	converter [yd] = 0.9144[m]

unit family MaritimeLength quantifies [[Length]]:
	# Maritime Units
	[ftm]
	[cable] = 100[ftm]
	[nmi] = 10[cable]

	base [nmi]
	converter [ftm] = 2.02667[yd]

unit family AstronomicalLength quantifies [[Length]]:
	[AU]
	[ly] = 63018.867925[AU]
	[pc] = 3.26156[ly]
	adopt [km]

	converter [AU] = 149597870700[m]

unit family StandardTime quantifies [[Time]]:
	[s]
	prefix [s] SIPrefixes only ([ms], [\mus], [ns], [ps], [fs], [as], [zs], [ys])
	[min] = 60[s]
	[hr] = 60[min]
	[d] = 24[hr]
	[yr] = 365.2421[d]

	base [s]

unit family SIMass quantifies [[Mass]]:
	[g]
	prefix [g] SIPrefixes
	
	base [kg]
	avoid ([dag],[dg],[cg])

unit family ImperialMass quantifies [[Mass]]:
	[messy and uninformative stuff]

unit family SIForce quantifies [[Force]]:
	[N]
	prefix [N] SIPrefixes

	base [N]
	avoid ([daN], [dN], [cN])
	converter [N] = [kg*m/s^2]

unit family SIEnergy quantifies [[Energy]]:
	[J]
	prefix [J] SIPrefixes

	base [J]
	avoid ([daJ], [dJ], [cJ])
	converter [J] = [N*m]

unit family ElectronVoltEnergy quantifies [[Energy]]:
	[eV]
	prefix [eV] SIPrefixes

	base [eV]
	avoid ([daeV], [deV], [ceV])
	converter [eV] = 1.6021766209e-19[J]

unit family SIFrequency quantifies [[Frequency]]:
	[Hz]
	prefix [Hz] SIPrefixes

	base [Hz]
	avoid ([daHz], [dHz], [cHz])
	converter [Hz] = 1/[s]
