#include <agent_defs.h>

extern "C" {
	int32_t RouterCmp(const struct Router* R1, const struct Router* R2);
	struct Router* RouterCtor(struct Router* x);
	void RouterDtor(struct Router* x);
}

using namespace AI;

CSimpleSearching::CSimpleSearching(struct WLList* inet):CAgntBase()
{
	buildIntrntMap(inet);

	return;
}

CSimpleSearching::~CSimpleSearching()
{
	WDeleteList(inetMap.intrnt);
	return;
}

void copyInet2InetMap(struct Router* Rtr, struct WLList* inetMap)
{
	int32_t x;
	struct Router* r = (struct Router*)calloc(1, sizeof * r);
	r->Id = Rtr->Id;
	for (x = 0; x < MAX_FWDGTBL_ENTRIES; ++x) {
		if (Rtr->FwdgTbl[x] != NULL) {
			r->FwdgTbl[x] = (struct RouteEntry*)malloc(sizeof(struct RouteEntry));
			r->FwdgTbl[x]->A = Rtr->FwdgTbl[x]->A;
			r->FwdgTbl[x]->I = Rtr->FwdgTbl[x]->I;
			r->FwdgTbl[x]->M = Rtr->FwdgTbl[x]->M;
			r->FwdgTbl[x]->Metric = Rtr->FwdgTbl[x]->Metric;
			r->FwdgTbl[x]->R = Rtr->FwdgTbl[x]->R;
		}
	}
	WAppendToList(inetMap, (void*)r);
	free(r);
	return;
}

void copYgIntfTbl2InetMap(struct Router* Rtr, struct Router* intfTbl[])
{
	intfTbl[Rtr->Id] = Rtr;
	return;
}

void CSimpleSearching::buildIntrntMap(struct WLList* inet)
{
	//inetMap.intrnt = inet;
	inetMap.intrnt = WCreateList((WCMPFP)RouterCmp, (WCTRFP)RouterCtor, (WDTRFP)RouterDtor);
	WIteratorList3(inet, (void*)inetMap.intrnt, (void(*)(void*, void*))copyInet2InetMap);

	//inetMap.gIntfTbl = gIntfTbl;
	WIteratorList3(inetMap.intrnt, (void*)inetMap.gIntfTbl, \
																 (void(*)(void*, void*))copYgIntfTbl2InetMap);
	return;
}