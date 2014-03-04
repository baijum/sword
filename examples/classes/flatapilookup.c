#include <stdio.h>
#include <stdlib.h>

#include <swordminflat.h>

int main(int argc, char **argv) {
	if (argc != 3) {
		fprintf(stderr, "\nusage: %s <modname> <\"lookup key\">\n"
							 "\tExample: lookup KJV \"James 1:19\"\n\n", argv[0]);
		exit(-1);
	}


	SWHANDLE mgr = org_crosswire_sword_SWMgr_new();

	SWHANDLE module = org_crosswire_sword_SWMgr_getModuleByName(mgr, argv[1]);

	if (!module) {
		fprintf(stderr, "Could not find module [%s].  Available modules:\n", argv[1]);
		const struct org_crosswire_sword_ModInfo *modInfos = org_crosswire_sword_SWMgr_getModInfoList(mgr);
		while (modInfos && modInfos->name) {
			fprintf(stderr, "[%s]\t - %s\n", modInfos->name, modInfos->description);
			++modInfos;
		}
		org_crosswire_sword_SWMgr_delete(mgr);
		exit(-1);
	}

	org_crosswire_sword_SWModule_setKeyText(module, argv[2]);

	// we render before we print keyText so our keyText snaps to the closest entry 
	const char *renderText = org_crosswire_sword_SWModule_renderText(module);
	printf("==Render=Entry============\n");
	printf("%s\n", org_crosswire_sword_SWModule_getKeyText(module));
	printf("%s\n", renderText);
	printf("==========================\n");

	org_crosswire_sword_SWMgr_delete(mgr);

	return 0;
}
