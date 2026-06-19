/* This is my cover letter. It runs. */

/*
 * According to my mum, my most overused first word was "why." It followed
 * me into code, and it's what brought me to Signaloid. So I wrote my
 * application the only honest way I could: as a probabilistic program —
 * confidence and uncertainty both shown, neither one hidden.
 *
 * In that same spirit: the words and the why are mine; I paired with an AI
 * to translate them into working Signaloid code.
 */

#include <uxhw.h>
#include <stdio.h>
#include <math.h>

/*
 * Each value below is a whole distribution, not a single number. On the C0
 * Reference core the program runs one sample at a time, and the platform
 * builds the full curve by collecting many runs — so a printed value is just
 * one draw (it jumps around), while the real answer is the curve drawn next
 * to it. Watch the curve tighten through Act 1 — that narrowing is the story.
 */

int main(void)
{
	/* ACT 1 — the "why" loop. I start knowing almost nothing: a wide curve
	 * near zero, where the spread is bigger than the mean. */
	double understanding = UxHwDoubleGaussDist(0.1, 0.4);

	/* I don't even know how deep this field goes, so "fully understanding it"
	 * is a range up here, not a fixed point. */
	double full_grasp = UxHwDoubleUniformDist(0.9, 1.0);

	/* Each good question closes about a quarter of the gap. */
	double learning_rate = 0.25;

	const char *questions[5] = {
		"What on earth is all of this? Something to do with statistics and probability, I think.",
		"What's a Monte Carlo method? ...ah — it's a simulation, and an expensive one.",
		"So how does Signaloid replace it? With a unique processor architecture, apparently.",
		"A chip that computes not just the numbers, but the probability wrapped around them — huh.",
		"Do I fully get it yet? Honestly, no — but it runs on a cloud platform, and that part I know cold."
	};

	printf("ACT 1 — learning by asking why\n");
	printf("(each value is a single draw; the curve beside it is the real distribution — watch it tighten)\n\n");

	for (int q = 0; q < 5; q++)
	{
		/* A question doesn't overwrite what I knew — it nudges it toward
		 * what's true and tightens the spread. The distribution does the rest. */
		understanding = understanding * (1.0 - learning_rate)
		              + full_grasp * learning_rate;

		printf("Question %d: %s\n", q + 1, questions[q]);
		printf("    understanding → %.2f\n\n", understanding);
	}

	/* Five whys in: wide and unsure at Q1, focused but never certain by Q5.
	 * The width still left is the room I keep learning in. The work I love most
	 * is making hard things feel learnable — a visual language for the
	 * difficult. (Fourteen years in film and TV before code; the instinct for
	 * how things should look stayed.) */
	printf("Five whys in: wide and unsure at Q1, focused but never certain by Q5.\n");
	printf("The width that's left is the room I keep learning in.\n\n");

	/* I've spent real time in the platform — clean foundation, room to grow
	 * (nav depth, spacing, dark mode), Vue + Vuetify underneath: home turf. */

	/* ACT 2 — the part I'm sure about: things I've lived, so these curves are
	 * tall and narrow. */

	/* Four years owning a cloud SaaS frontend (five-plus in the craft):
	 * complexity without flinching, knowing where data flows quietly break. */
	double cloud_saas_experience = UxHwDoubleGaussDist(0.90, 0.05);

	/* Grew four devs into stronger engineers; took one from the fundamentals
	 * to owning a whole feature alone. */
	double mentorship_track_record = UxHwDoubleGaussDist(0.88, 0.06);

	/* Empathy, honesty, listening — the narrowest curve, because it's
	 * non-negotiable. Good communication is a clean signal: less noise. */
	double values_alignment = UxHwDoubleGaussDist(0.94, 0.02);

	/* The honest one: how well I know your domain today — the variable from
	 * Act 1, trending right but still the widest of the four. */
	double domain_understanding = understanding;

	/* Combine them, weighted — leaning on what matters most and what I'm
	 * surest of, while still giving the moving target real weight. */
	double probability_of_good_hire =
	      0.30 * values_alignment
	    + 0.25 * cloud_saas_experience
	    + 0.20 * mentorship_track_record
	    + 0.25 * domain_understanding;

	printf("ACT 2 — the parts I'm sure about (tall + narrow = certain)\n\n");
	printf("    cloud SaaS ownership   → %.2f   (tall, narrow)\n", cloud_saas_experience);
	printf("    mentorship             → %.2f   (tall, narrow)\n", mentorship_track_record);
	printf("    values alignment       → %.2f   (the narrowest — surest)\n", values_alignment);
	printf("    domain understanding   → %.2f   (still the widest — learning)\n\n", domain_understanding);

	/* The center is fixed by the input means, so I can state it exactly:
	 * 0.30*0.94 + 0.25*0.90 + 0.20*0.88 + 0.25*(~0.75) ≈ 0.87, and the spread
	 * is about ±0.03 — that width is what you see in the curve below. */
	printf("    probability of a good hire → %.2f   (one draw)\n\n",
	       probability_of_good_hire);
	printf("Mean probability of good hire: 0.87, give or take ±0.03. "
	       "The uncertainty is the honest part. — Julia\n");

	return 0;
}
