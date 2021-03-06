#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_WHOL PT_WHOL 40
Element_WHOL::Element_WHOL()
{
	Identifier = "DEFAULT_PT_WHOL";
	Name = "VENT";
	Colour = PIXPACK(0xEFEFEF);
	MenuVisible = 0;
	MenuSection = SC_SPECIAL;
	Enabled = 1;

	Advection = 0.0f;
	AirDrag = 0.00f * CFDS;
	AirLoss = 0.95f;
	Loss = 0.00f;
	Collision = 0.0f;
	Gravity = 0.0f;
	Diffusion = 0.00f;
	HotAir = 0.010f	* CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 100;

	Temperature = R_TEMP-16.0f+273.15f;
	HeatConduct = 255;
	Description = "Air vent, creates pressure and pushes other particles away.";

	Properties = TYPE_SOLID;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;

	Update = &Element_WHOL::update;
}

//#TPT-Directive ElementHeader Element_WHOL static int update(UPDATE_FUNC_ARGS)
int Element_WHOL::update(UPDATE_FUNC_ARGS)
{
	return Element_ETRD::craft_with(UPDATE_FUNC_SUBCALL_ARGS, PT_ETRD, PT_PUMP);
}

Element_WHOL::~Element_WHOL() {}
