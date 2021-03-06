#include <err.h>
#include "scrappie_stdlib.h"

#include "scrappie_subcommands.h"

enum scrappie_mode get_scrappie_mode(const char *modestr) {
    if (0 == strcmp(modestr, "help")) {
        return SCRAPPIE_MODE_HELP;
    }
    if (0 == strcmp(modestr, "events")) {
        return SCRAPPIE_MODE_EVENTS;
    }
    if (0 == strcmp(modestr, "raw")) {
        return SCRAPPIE_MODE_RAW;
    }
    if (0 == strcmp(modestr, "licence") || 0 == strcmp(modestr, "license")) {
        return SCRAPPIE_MODE_LICENCE;
    }
    if (0 == strcmp(modestr, "version")) {
        return SCRAPPIE_MODE_VERSION;
    }

    return SCRAPPIE_MODE_INVALID;
}

const char *scrappie_mode_string(const enum scrappie_mode mode) {
    switch (mode) {
    case SCRAPPIE_MODE_HELP:
        return "help";
    case SCRAPPIE_MODE_EVENTS:
        return "events";
    case SCRAPPIE_MODE_RAW:
        return "raw";
    case SCRAPPIE_MODE_LICENCE:
        return "licence";
    case SCRAPPIE_MODE_VERSION:
        return "version";
    case SCRAPPIE_MODE_INVALID:
        errx(EXIT_FAILURE, "Invalid scrappie mode\n");
    default:
        errx(EXIT_FAILURE, "Scrappie enum failure -- report bug\n");
    }

    return NULL;
}

const char *scrappie_mode_description(const enum scrappie_mode mode) {
    switch (mode) {
    case SCRAPPIE_MODE_HELP:
        return "Print general help or help about specific Scrappie command.";
    case SCRAPPIE_MODE_EVENTS:
        return "Base call from event based data.";
    case SCRAPPIE_MODE_RAW:
        return "Base call directly from raw signal.";
    case SCRAPPIE_MODE_LICENCE:
        return "Print licensing information.";
    case SCRAPPIE_MODE_VERSION:
        return "Print version information.";
    case SCRAPPIE_MODE_INVALID:
        errx(EXIT_FAILURE, "Invalid scrappie mode\n");
    default:
        errx(EXIT_FAILURE, "Scrappie enum failure -- report bug\n");
    }

    return NULL;
}

int fprint_scrappie_commands(FILE * fp, bool header) {
    int ret = 0;
    if (header) {
        ret = fputs("Basic usage:\n", fp);
    }
    for (enum scrappie_mode i = 0; i < scrappie_ncommand; i++) {
        if (EOF != ret) {
            ret = fprintf(fp, "* scrappie %-10s%s\n", scrappie_mode_string(i),
                          scrappie_mode_description(i));
        }
    }
    return ret;
}
